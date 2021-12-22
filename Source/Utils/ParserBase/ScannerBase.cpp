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
#include "Utils/ParserBase/ScannerBase.h"
#include "Utils/Char.h"
#include "Utils/ParserBase/ParseError.h"

namespace Hack
{
    ScannerBase::ScannerBase() :
        _stream(nullptr),
        _line(0)
    {
    }

    void ScannerBase::attach(IStream* stream, const String& file)
    {
        _stream = stream;
        _file   = file;
        _line   = 1;
    }

    const String& ScannerBase::getString(const size_t& i) const
    {
        return _stringTable.at(i);
    }

    void ScannerBase::getString(String& dest, const size_t& i) const
    {
        _stringTable.at(dest, i);
    }

    int ScannerBase::getInt(const size_t& i) const
    {
        return _intTable.at(i);
    }

    bool ScannerBase::hasString(const size_t id) const
    {
        return _stringTable.contains(id);
    }

    [[noreturn]] void ScannerBase::syntaxErrorThrow(const String& message) const
    {
        throw ParseError(0, _file, _line, message);
    }

    void ScannerBase::scanLineComment()
    {
        int ch = _stream->peek();
        while (ch != '\r' && ch != '\n')
        {
            ch = _stream->get();
            if (ch == '\r' && _stream->peek() == '\n')
                ch = _stream->get();
        }
        ++_line;
    }

    void ScannerBase::scanMultiLineComment()
    {
        int ch = _stream->peek();
        // save doc string?
        // /** | /*!
        while (ch > 0)
        {
            ch = _stream->get();
            if (ch == '*' && _stream->peek() == '/')
            {
                _stream->get();
                break;
            }
            if (ch == '\r' || ch == '\n')
            {
                if (ch == '\r' && _stream->peek() == '\n')
                    ch = _stream->get();
                ++_line;
            }
        }
    }

    void ScannerBase::scanWhiteSpace() const
    {
        int ch = 0;
        while (ch != -1)
        {
            if (isWhiteSpace(_stream->peek()))
                ch = _stream->get();
            else
                break;
        }
    }

}  // namespace Hack
