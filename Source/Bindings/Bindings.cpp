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
#ifdef WIN32
#define EXPORT_API extern "C" _declspec(dllexport)
#else
#define EXPORT_API extern "C"
#endif

#include "Assembler/Instruction.h"
#include "Assembler/Parser.h"
#include "Chips/Computer.h"
#include "Utils/Exceptions/Exception.h"

typedef struct HandleType
{
    uint64_t  type;
    uintptr_t ptr;
} const* Handle;

namespace Hack::Binding
{
    using namespace Chips;
    using namespace Assembler;

    constexpr uint64_t ComputerType = 0x6543F55D6F4A3D0F;
    constexpr uint64_t RomType      = 0x06D5DAF556F4ADB3;
    constexpr uint64_t RamType      = 0x3D654F7A36F4A3D0;

    class RomWrapper
    {
    private:
        const uint64_t type = RomType;

        Rom32* _rom;

        mutable String _cache;

    public:
        explicit RomWrapper(Rom32* rom32) : _rom(rom32)
        {
        }

        int get(const int idx) const
        {
            // the index must be less than 0x7FFF (32K)
            if (_rom && (idx >= 0 && idx < 0x7FFF) && type == RomType)
                return _rom->get(idx);
            return -1;
        }

        const char* decode(const int idx) const
        {
            _cache.clear();

            const int val = get(idx);
            if (val >= 0)
            {
                const Instruction instruction((uint16_t)val);
                _cache = instruction.asString();
            }
            return _cache.c_str();
        }

        static const RomWrapper* cast(Handle handle)
        {
            if (handle != nullptr)
            {
                const uint64_t check = *(const uint64_t*)handle;
                if (check == RomType)
                    return (const RomWrapper*)handle;
            }
            return nullptr;
        }
    };

    class RamWrapper
    {
    private:
        const uint64_t type = RamType;

        Memory* _memory;

    public:
        explicit RamWrapper(Memory* mem) : _memory(mem)
        {
        }

        int get(const int idx) const
        {
            if (_memory && type == RamType)
                return _memory->get(idx);
            return 0;
        }

        void zeroMemory() const
        {
            if (_memory && type == RamType)
                _memory->zero();
        }

        static const RamWrapper* cast(const Handle handle)
        {
            if (handle != nullptr)
            {
                const uint64_t check = *(const uint64_t*)handle;
                if (check == RamType)
                    return (const RamWrapper*)handle;
            }
            return nullptr;
        }
    };

    class ComputerWrapper
    {
    private:
        const uint64_t type = ComputerType;

        Computer*   _computer;
        RomWrapper* _rom;
        RamWrapper* _ram;

        mutable String _cache;
        mutable String _error;

        mutable uint8_t* _bytes;

    public:
        ComputerWrapper() : _computer(new Computer()), _bytes(nullptr)
        {
            _rom   = new RomWrapper(_computer->getRom());
            _ram   = new RamWrapper(_computer->getRam());
            _bytes = new uint8_t[0x80001];
        }

        ~ComputerWrapper()
        {
            delete _rom;
            delete _ram;
            delete _computer;
            delete[] _bytes;
        }

        void update() const
        {
            if (_computer && type == ComputerType)
                _computer->update(true);
        }

        void reset() const
        {
            if (_computer && type == ComputerType)
                _computer->reset();
        }

        static int getScreenBufferSize()
        {
            return 0x80000;
        }

        void updateScreen() const
        {
            if (!_computer || type != ComputerType)
                return;

            for (int i = 0; i < 0x2000; ++i)
                _computer->update(false);

            const uint16_t* pointer =
                _computer->getRam()->pointer(Memory::ScreenAddress);

            uint8_t* bytes = (uint8_t*)_bytes;
            for (int i = 0; i < 0x2000; ++i)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (pointer[i] & 1 << j)
                    {
                        *bytes++ = 0x00;
                        *bytes++ = 0x00;
                        *bytes++ = 0x00;
                        *bytes++ = 0xFF;
                    }
                    else
                    {
                        *bytes++ = 0xFF;
                        *bytes++ = 0xFF;
                        *bytes++ = 0xFF;
                        *bytes++ = 0xFF;
                    }
                }
            }
        }

        uint8_t* getScreenBuffer() const
        {
            return _bytes;
        }

        RamWrapper* getRam() const
        {
            return _ram;
        }

        RomWrapper* getRom() const
        {
            return _rom;
        }

        const CpuState& getState() const
        {
            if (_computer && type == ComputerType)
                return _computer->getState();
            return Computer::NullState;
        }

        bool load(const String& src) const
        {
            _error.clear();
            Parser psr;
            try
            {
                StringStream ss;
                ss << src;
                psr.parse(ss);

                Parser::Instructions inst = psr.getInstructions();

                _computer->load(inst.data(), inst.size());
                return true;
            }
            catch (Exception& ex)
            {
                _error = ex.what();
                return false;
            }
        }

        const char* decode(const int val) const
        {
            _cache.clear();
            if (val >= 0)
            {
                const Instruction instruction((uint16_t)val);
                _cache = instruction.asString();
            }
            return _cache.c_str();
        }

        const char* getLastError() const
        {
            return _error.c_str();
        }

        static const ComputerWrapper* cast(Handle handle)
        {
            if (handle != nullptr)
            {
                const uint64_t check = *(const uint64_t*)handle;
                if (check == ComputerType)
                    return (const ComputerWrapper*)handle;
            }
            return nullptr;
        }
    };

}  // namespace Hack::Binding

using namespace Hack::Binding;

EXPORT_API void* ComputerAllocate(size_t len)
{
    return malloc(len);
}

EXPORT_API void ComputerFree(void* handle)
{
    return free(handle);
}

EXPORT_API Handle CreateComputer()
{
    return (Handle) new ComputerWrapper();
}

EXPORT_API void DestroyComputer(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    delete wrapper;
}

EXPORT_API void UpdateComputer(Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        wrapper->update();
}

EXPORT_API void RestartComputer(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        wrapper->reset();
}

EXPORT_API const char* ComputerGetLastError(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getLastError();
    return "";
}

EXPORT_API int ComputerGetScreenBufferSize(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getScreenBufferSize();
    return 0;
}

EXPORT_API uint8_t* ComputerGetScreenBuffer(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getScreenBuffer();
    return nullptr;
}

EXPORT_API void ComputerUpdateScreen(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        wrapper->updateScreen();
}

EXPORT_API const char* DecodeInstruction(const Handle handle, const int value)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->decode(value);
    return "";
}

EXPORT_API CpuState ComputerGetState(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState();

    return Computer::NullState;
}

bool IsMemoryValid(const char* memory, const int length)
{
    bool result = false;
    if (memory && length > 0 && length < 0xFFFF)
    {
        result = true;
        for (int i = 0; i < length && result; ++i)
        {
            const char ch = memory[i];

            result = ch >= 32 && ch < 127 || ch == '\n' || ch == '\r';
        }
    }
    return result;
}

EXPORT_API int ComputerLoadSource(const Handle handle,
                                  char*        memory,
                                  const int    length)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper && IsMemoryValid(memory, length))
        return wrapper->load(Hack::String(memory, length)) ? 0 : 1;
    return 1;
}

EXPORT_API Handle ComputerGetRam(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return (Handle)wrapper->getRam();
    return nullptr;
}

EXPORT_API Handle ComputerGetRom(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return (Handle)wrapper->getRom();
    return nullptr;
}

EXPORT_API int RamGetValue(const Handle handle, const int index)
{
    const RamWrapper* wrapper = RamWrapper::cast(handle);
    if (wrapper != nullptr)
        return wrapper->get(index);
    return -1;
}

EXPORT_API void RamZeroMemory(const Handle handle)
{
    const RamWrapper* wrapper = RamWrapper::cast(handle);
    if (wrapper != nullptr)
        wrapper->zeroMemory();
}

EXPORT_API int RomGetValue(const Handle handle, int index)
{
    const RomWrapper* wrapper = RomWrapper::cast(handle);
    if (wrapper)
        return wrapper->get(index);
    return -1;
}

EXPORT_API const char* RomGetValueDecoded(const Handle handle, const int index)
{
    const RomWrapper* wrapper = RomWrapper::cast(handle);
    if (wrapper)
        return wrapper->decode(index);
    return "";
}

EXPORT_API int CpuGetInstructionPointer(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().pc;

    return 0;
}

EXPORT_API int CpuGetOutputValue(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().outM;
    return 0;
}

EXPORT_API int CpuGetOutputAddress(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().addrM;
    return 0;
}

EXPORT_API int CpuGetDRegister(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().regD;
    return 0;
}

EXPORT_API int CpuGetARegister(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().regA;
    return 0;
}

EXPORT_API int CpuGetClock(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().clock;
    return 0;
}

EXPORT_API int CpuGetInstruction(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().inst;
    return 0;
}

EXPORT_API int CpuGetLoadRam(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().writeM;
    return 0;
}

EXPORT_API int CpuGetInput(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().ram;
    return 0;
}

EXPORT_API int CpuGetReset(const Handle handle)
{
    const ComputerWrapper* wrapper = ComputerWrapper::cast(handle);
    if (wrapper)
        return wrapper->getState().reset;
    return 0;
}
