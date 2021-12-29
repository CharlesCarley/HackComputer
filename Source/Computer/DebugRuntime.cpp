/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "Computer/DebugRuntime.h"
#include "Assembler/Instruction.h"
#include "Chips/Computer.h"
#include "Utils/Char.h"
#include "Utils/Exception.h"
#include "Utils/UserInterface/Context.h"

using namespace Hack::Chips;
using namespace Hack::Ui;

namespace Hack::Computer
{
    enum Colors
    {
        Grey = CP_USER,
        Highlight,
        WireTitle,
        Action,
        Action2,
        Wire,
        Title,
        WireShadow,
        WireLight
    };

    namespace Detail
    {
        constexpr int CpuWidth   = 24;
        constexpr int CpuWidthH  = CpuWidth >> 1;
        constexpr int CpuHeight  = 12;
        constexpr int CpuHeightH = CpuHeight >> 1;
        constexpr int TitleOffs  = 2;

        constexpr int SideBarWidth  = 20;
        constexpr int SideBarWidthD = SideBarWidth << 1;
        const Point   RegSize       = Point(12, 3);

    }  // namespace Detail

    class DebugRuntimePrivate
    {
    private:
        int      _input;
        int      _mode;
        bool     _block;
        Context* _ctx;
        Memory*  _ram;
        Rom32*   _rom;
        CpuState _cpuState;
        CpuState _prevCpuState;

    public:
        DebugRuntimePrivate() :
            _input(PR_NO_INPUT),
            _mode(1),
            _block(true),
            _ctx(nullptr),
            _ram(nullptr),
            _rom(nullptr),
            _cpuState{},
            _prevCpuState{}
        {
        }

        ~DebugRuntimePrivate()
        {
            delete _ctx;
            _ctx = nullptr;
        }

        void initialize(Chips::Computer* computer)
        {
            _rom = computer->rom();
            _ram = computer->memory();

            _ctx = new Context();
            _ctx->createColor(Color(0x62627c));  // Grey
            _ctx->createColor(Color(0x9f9faf));  // Highlight
            _ctx->createColor(Color(0x5a5a7f));  // WireTitle
            _ctx->createColor(Color(0xe94545));  // Action
            _ctx->createColor(Color(0x72728c));  // Action2
            _ctx->createColor(Color(0x3f3f59));  // Wire
            _ctx->createColor(Color(0x8787bf));  // Title
            _ctx->createColor(Color(0x30303f));  // WireShadow
            _ctx->createColor(Color(0x5a5a7f));  // WireShadow
        }

        int input() const
        {
            return _input;
        }

        bool block() const
        {
            return _block;
        }

        void processEvents(Chips::Computer* computer)
        {
            if (!_ctx)
                throw Exception("Context is null");

            _input = _ctx->poll(_block);

            if (_input == PR_C)
                _block = !_block;
            if (_input == PR_R)
                computer->reset();
            if (_input == PR_1)
                _mode = 0;
            if (_input == PR_2)
                _mode = 1;
            if (_input == PR_3)
                _mode = 2;
            if (_input == PR_4)
                _mode = 3;
            if (_input == PR_ESC)
                _input = PR_EXIT;
        }

        void flushMemory(Chips::Computer* computer)
        {
            _ctx->clear();

            _cpuState = computer->state();

            render(*_ctx);

            _ctx->flush();
            _prevCpuState = _cpuState;
        }

        void displayMemoryContents(Context&         ctx,
                                   const Rectangle& bounds,
                                   const String&    value,
                                   const int        index,
                                   const int        offset,
                                   const bool       highlight) const
        {
            if (index + offset >= 0)
            {
                if (highlight)
                {
                    ctx.background(WireShadow);
                    ctx.foreground(WireShadow);
                    ctx.line(bounds.x + 1,
                             bounds.midY(),
                             bounds.w - 2,
                             OR_HORIZONTAL);
                    ctx.foreground(Highlight);
                }
                else
                {
                    ctx.background(0);
                    if (value.at(0) == '@')
                        ctx.foreground(Action2);
                    else
                        ctx.foreground(Grey);
                }

                ctx.string(value,
                           bounds.right() - (int)value.size() - 1,
                           (bounds.midY()) + index);

                if (highlight)
                    ctx.foreground(Action);
                else
                    ctx.foreground(Grey);

                String s;
                Char::toString(s, index + offset);
                ctx.string(
                    s, (bounds.x + 6) - (int)s.size(), (bounds.midY()) + index);
            }
        }

        void displayRom(Context& ctx) const
        {
            using namespace Ui;
            using namespace Detail;

            const int height = ctx.height();

            ctx.reset();

            const Rectangle bounds = {2, 2, SideBarWidth, height - 4};
            ctx.foreground(Wire);
            ctx.rectangle(bounds);
            ctx.foreground(Title);
            ctx.string("[ Rom ]", bounds.x + 2, bounds.y);
            ctx.foreground(Wire);
            const int hh = bounds.h >> 1;

            for (int i = -hh + 1; i < hh - 1; ++i)
            {
                int iVal = _cpuState.pc + i;

                const uint16_t value = _rom->get(iVal);

                String                 v;
                Assembler::Instruction is(value);
                is.string(v);

                displayMemoryContents(
                    ctx, bounds, v, i, _cpuState.pc, iVal == _cpuState.pc);
            }
        }

        void displayRam(Context& ctx) const
        {
            using namespace Ui;
            using namespace Detail;

            const int height = ctx.height();
            const int width  = ctx.width();

            ctx.reset();

            int w = SideBarWidth;
            if (_mode == 3)
                w += 5;

            const Rectangle bounds = {
                width - w - 3,
                2,
                w,
                height - 4,
            };

            ctx.foreground(Wire);
            ctx.rectangle(bounds);

            ctx.foreground(Title);
            ctx.string("[ Ram ]", bounds.left() + TitleOffs, bounds.top());
            ctx.foreground(Wire);

            const int hh = bounds.h >> 1;

            for (int i = -hh + 1; i < hh - 1; ++i)
            {
                const int iVal = _cpuState.addrM + i;

                const uint16_t vi = _ram->get(iVal);
                String         v;
                if (_mode == 1)
                    v = Char::toString((int16_t)vi);
                else if (_mode == 2)
                    v = Char::toHexString(vi);
                else if (_mode == 3)
                    v = Char::toBinaryString(vi);
                else
                    v = Char::toString(vi);

                displayMemoryContents(ctx,
                                      bounds,
                                      v,
                                      i,
                                      _cpuState.addrM,
                                      iVal == _cpuState.addrM);
            }
        }

        void displayCpu(Context& ctx) const
        {
            const int height = ctx.height();
            const int width  = ctx.width();
            using namespace Detail;

            const Rectangle bounds = {
                SideBarWidth + 6,
                3,
                width - SideBarWidthD - 12,
                height - 6,
            };

            const Rectangle cpuRect = {
                bounds.midX() - CpuWidthH,
                bounds.midY() - CpuHeightH,
                CpuWidth,
                CpuHeight,
            };

            ctx.reset();
            ctx.foreground(Wire);

            ctx.rectangle(cpuRect);
            ctx.foreground(Title);
            ctx.string("[ CPU ]", cpuRect.left() + TitleOffs, cpuRect.top());

            String v;

            const int halfToEdge       = (bounds.w >> 1) - CpuWidth;
            const int halfOfHalfToEdge = halfToEdge >> 1;

            //  Write
            int offs = 4;

            ctx.foreground(_prevCpuState.writeM != _cpuState.writeM ? WireLight
                                                                    : Wire);
            ctx.line(cpuRect.right(),
                     bounds.midY() + offs,
                     halfOfHalfToEdge,
                     OR_HORIZONTAL);
            ctx.foreground(WireTitle);
            ctx.string("Write", cpuRect.right() - 1, bounds.midY() + offs);

            //  Address
            ctx.foreground(_prevCpuState.addrM != _cpuState.addrM ? WireLight
                                                                  : Wire);
            ctx.line(cpuRect.right(),
                     bounds.midY(),
                     halfToEdge + SideBarWidth,
                     OR_HORIZONTAL);
            ctx.foreground(WireTitle);
            ctx.string("Address", cpuRect.right() - 1, bounds.midY());

            //  Output
            offs = 2;
            ctx.foreground(_prevCpuState.outM != _cpuState.outM ? WireLight
                                                                : Wire);
            ctx.line(cpuRect.right(),
                     bounds.midY() + offs,
                     halfToEdge >> 1,
                     OR_HORIZONTAL);
            ctx.foreground(WireTitle);
            ctx.string("Out", cpuRect.right() - 1, bounds.midY() + offs);

            // Wiring Out -> Ram
            ctx.foreground(_prevCpuState.writeM != _cpuState.writeM &&
                                   _cpuState.writeM
                               ? WireLight
                               : Wire);

            ctx.moveTo(cpuRect.right() + halfOfHalfToEdge, bounds.bottom() + 1);
            ctx.lineTo(cpuRect.right() + halfOfHalfToEdge,
                       bounds.midY() + 3,
                       OR_VERTICAL);

            ctx.character(CS_RECT_RT,
                          cpuRect.right() + halfOfHalfToEdge,
                          bounds.midY() + 4);

            ctx.moveTo(cpuRect.right() + halfOfHalfToEdge, bounds.bottom() + 1);
            ctx.lineTo(width - 3, bounds.bottom() + 1, OR_HORIZONTAL);
            ctx.lineTo(width - 3, bounds.midY(), OR_VERTICAL);

            ctx.character(CS_RECT_LB,
                          cpuRect.right() + halfOfHalfToEdge,
                          bounds.bottom() + 1);
            ctx.character(CS_RECT_RB, width - 3, bounds.bottom() + 1);
            ctx.character(CS_RECT_RT, width - 3, bounds.midY());

            ctx.foreground(Action);
            Char::toString(v, _cpuState.outM);
            ctx.string(v,
                       cpuRect.right() + halfOfHalfToEdge + 1 - (int)v.size(),
                       bounds.midY() + 2);
            ctx.character(_cpuState.writeM ? '1' : '0',
                          cpuRect.right() + halfOfHalfToEdge,
                          bounds.midY() + 4);

            // Rom -> CPU

            ctx.foreground(_prevCpuState.inst != _cpuState.inst ? WireLight
                                                                : Wire);
            ctx.moveTo(4, bounds.midY());
            ctx.lineTo(cpuRect.left(), bounds.midY(), OR_HORIZONTAL);

            // program counter
            ctx.foreground(_prevCpuState.pc != _cpuState.pc ? WireLight : Wire);
            ctx.moveTo(1, bounds.bottom() + 1);
            ctx.lineTo(1, bounds.midY(), OR_VERTICAL);
            ctx.character(CS_RECT_LT, 1, bounds.midY());
            ctx.moveTo(bounds.midX(), bounds.bottom() + 1);
            ctx.lineTo(bounds.midX(), cpuRect.bottom(), OR_VERTICAL);

            ctx.moveTo(1, bounds.bottom() + 1);
            ctx.lineTo(bounds.midX(), bounds.bottom() + 1, OR_HORIZONTAL);
            ctx.character(CS_RECT_LB, 1, bounds.bottom() + 1);
            ctx.character(CS_RECT_RB, bounds.midX(), bounds.bottom() + 1);
            ctx.lineTo(bounds.midX(), bounds.bottom() + 1, OR_HORIZONTAL);
            ctx.character(CS_RECT_LB, 1, bounds.bottom() + 1);
            ctx.character(CS_RECT_RB, bounds.midX(), bounds.bottom() + 1);

            ctx.foreground(WireTitle);
            ctx.string("Next", bounds.left() + 5, bounds.bottom() + 1);

            // RAM -> CPU

            int boundsOffset = bounds.right() + 3;
            if (_mode == 3)
                boundsOffset -= 5;

            ctx.foreground(_prevCpuState.ram != _cpuState.ram ? WireLight
                                                              : Wire);
            ctx.moveTo(cpuRect.left() - halfOfHalfToEdge, bounds.top() + 1);
            ctx.lineTo(boundsOffset, bounds.top() + 1, OR_HORIZONTAL);
            ctx.moveTo(cpuRect.left() - halfOfHalfToEdge, cpuRect.top() + 3);
            ctx.lineTo(cpuRect.left() - halfOfHalfToEdge,
                       bounds.top() + 1,
                       OR_VERTICAL);
            ctx.moveTo(cpuRect.left() - halfOfHalfToEdge, cpuRect.top() + 3);
            ctx.lineTo(cpuRect.left(), cpuRect.top() + 3, OR_HORIZONTAL);
            ctx.character(CS_RECT_LT,
                          cpuRect.left() - halfOfHalfToEdge,
                          bounds.top() + 1);
            ctx.character(CS_RECT_LB,
                          cpuRect.left() - halfOfHalfToEdge,
                          cpuRect.top() + 3);

            ctx.foreground(WireTitle);
            ctx.string(
                "In", cpuRect.left() - halfOfHalfToEdge + 1, cpuRect.top() + 3);

            ctx.foreground(Action);
            Char::toString(v, _cpuState.ram);
            ctx.string(
                v, cpuRect.left() - (int)v.size() + 1, cpuRect.top() + 3);

            ctx.foreground(Action);

            const Assembler::Instruction is(_cpuState.inst);
            is.string(v);
            ctx.string(v, cpuRect.left() - (int)v.size() + 1, bounds.midY());

            // A Register.
            const Rectangle aRect = {
                cpuRect.midX() - 9, cpuRect.midY() + 1, 18, 3};
            ctx.foreground(Wire);
            ctx.rectangle(aRect);
            ctx.foreground(WireTitle);
            ctx.string("[A]", aRect.left() + TitleOffs, aRect.top());
            ctx.foreground(Wire);
            ctx.character('^', aRect.midX(), aRect.bottom() - 1);
            ctx.foreground(_cpuState.clock ? WireLight : WireTitle);
            ctx.character(
                _cpuState.clock ? '1' : '0', aRect.midX(), aRect.bottom());
            ctx.foreground(_prevCpuState.regA != _cpuState.regA ? Action
                                                                : WireTitle);
            Char::toString(v, _cpuState.regA);
            ctx.string(v, aRect.midX() - ((int)v.size() >> 1), aRect.midY());

            // D Register.
            ctx.foreground(Wire);
            const Rectangle dRect = {
                cpuRect.midX() - 9, cpuRect.midY() - 4, 18, 3};
            ctx.rectangle(dRect);
            ctx.foreground(WireTitle);
            ctx.string("[D]", dRect.left() + TitleOffs, dRect.top());
            ctx.foreground(Wire);
            ctx.character('^', dRect.midX(), dRect.bottom() - 1);
            ctx.foreground(_cpuState.clock ? WireLight : WireTitle);
            ctx.character(
                _cpuState.clock ? '1' : '0', dRect.midX(), dRect.bottom());
            ctx.foreground(_prevCpuState.regD != _cpuState.regD ? Action
                                                                : WireTitle);
            Char::toString(v, _cpuState.regD);
            ctx.string(v, dRect.midX() - ((int)v.size() >> 1), dRect.midY());

            // Reset
            ctx.foreground(_cpuState.reset != _prevCpuState.reset ? WireLight
                                                                  : Wire);
            ctx.line(cpuRect.left() - 11, bounds.midY() + 3, 11, OR_HORIZONTAL);
            ctx.foreground(_cpuState.reset ? Action : WireTitle);
            ctx.string("Reset", cpuRect.left() - 11, bounds.midY() + 3);
        }

        void render(Context& ctx) const
        {
            using namespace Ui;
            ctx.reset();

            const int width = ctx.width();

            ctx.background(WireShadow);
            ctx.foreground(WireShadow);
            ctx.line(0, 0, width, OR_HORIZONTAL);

            const String v = "[ Hack Computer ]";
            ctx.background(WireShadow);
            ctx.foreground(Highlight);
            ctx.string(v, (width >> 1) - ((int)v.size() >> 1), 0);
            ctx.background(0);

            displayCpu(ctx);
            displayRom(ctx);
            displayRam(ctx);
            ctx.useExtended(true);
        }
    };

    DebugRuntime::DebugRuntime() :
        _private(new DebugRuntimePrivate())
    {
    }

    DebugRuntime::~DebugRuntime()
    {
        delete _private;
        _private = nullptr;
    }

    bool DebugRuntime::shouldUpdate()
    {
        return _private->input() == PR_UP_ARROW || _private->input() == PR_R ||
               !_private->block();
    }

    void DebugRuntime::initialize(Chips::Computer* computer, Chips::Screen*) const
    {
        _private->initialize(computer);
        _private->flushMemory(computer);
    }

    bool DebugRuntime::exitRequest() const
    {
        return _private->input() == PR_EXIT;
    }

    void DebugRuntime::processEvents(Chips::Computer* computer) const
    {
        _private->processEvents(computer);
    }

    void DebugRuntime::flushMemory(Chips::Computer* computer) const
    {
        _private->flushMemory(computer);
    }

    void DebugRuntime::update(Chips::Computer* computer) const
    {
        if (computer)
        {
            const int16_t rate = getRate() - 1;
            for (int16_t i = 0; i < rate; ++i)
                computer->update(false);
            computer->update(true);
        }
    }

}  // namespace Hack::Computer
