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
#pragma once
#include <bitset>
#ifdef CHECK_INT_BOUNDS
#include "Utils/Exception.h"
#endif
#include "Utils/Console.h"

namespace Hack::Chips
{
    enum BitIndex
    {
        Bit0  = 0x0001,
        Bit1  = 0x0002,
        Bit2  = 0x0004,
        Bit3  = 0x0008,
        Bit4  = 0x0010,
        Bit5  = 0x0020,
        Bit6  = 0x0040,
        Bit7  = 0x0080,
        Bit8  = 0x0100,
        Bit9  = 0x0200,
        Bit10 = 0x0400,
        Bit11 = 0x0800,
        Bit12 = 0x1000,
        Bit13 = 0x2000,
        Bit14 = 0x4000,
        Bit15 = 0x8000,
    };

    union bit16_t
    {
        uint16_t s;
        uint8_t  b[2];

        explicit operator size_t() const
        {
            return s;
        }
    };

    union bit32_t
    {
        uint32_t i;
        uint16_t s[2];
        uint8_t  b[4];

        explicit operator size_t() const
        {
            return i;
        }
    };

    union bit64_t
    {
        uint64_t ll;
        uint32_t i[2];
        uint16_t s[4];
        uint8_t  b[8];

        explicit operator size_t() const
        {
            return ll;
        }
    };

    template <typename T, uint8_t Count>
    class BitUtils
    {
    public:
        static void unpack(const T& value, bool* array);

        static void unpack(const T& value, uint8_t* array);

        static T pack(const uint8_t* array);

        static T pack(const char* array);

        static T pack(const bool* array);

        template <uint8_t N>
        static T pack(const bool array[N]);

        static T extract(const T& in, const T& lo, const T& hi);

        static bool getBit(const T& bits, const T& index);

        static void setBit(T& bits, const T& index);

        static void assignBit(T& bits, const T& index);

        static void clearBit(T& bits, const T& index);

        static void applyBit(T& bits, const T& index, bool value);

        static void printBit(const T& bits);
    };

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::unpack(const T& value, bool* array)
    {
        for (uint8_t i = 0; i < Count; ++i)
            array[i] = (value & 1 << i) != 0;
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::unpack(const T& value, uint8_t* array)
    {
        for (uint8_t i = 0; i < Count; ++i)
            array[i] = (value & 1 << i) != 0;
    }

    template <typename T, uint8_t Count>
    T BitUtils<T, Count>::pack(const uint8_t* array)
    {
        T ret = 0;
        for (uint8_t i = 0; i < Count; ++i)
        {
            if (array[i])
                ret |= 1 << i;
        }
        return ret;
    }

    template <typename T, uint8_t Count>
    T BitUtils<T, Count>::pack(const char* array)
    {
        T ret = 0;
        for (uint8_t i = 0; i < Count; ++i)
        {
            if (array[i])
                ret |= 1 << (Count - 1 - i);
        }
        return ret;
    }

    template <typename T, uint8_t Count>
    T BitUtils<T, Count>::pack(const bool* array)
    {
        T ret = 0;
        for (uint8_t i = 0; i < Count; ++i)
        {
            if (array[i])
                ret |= 1 << i;
        }
        return ret;
    }

    template <typename T, uint8_t Count>
    template <uint8_t N>
    T BitUtils<T, Count>::pack(const bool array[N])
    {
#ifdef CHECK_INT_BOUNDS
        if (N >= sizeof(T) * 8)
            throw IndexOutOfBounds();
#endif
        T ret = 0;
        for (size_t i = 0; i < N; ++i)
        {
            if (array[i])
                ret |= 1 << i;
        }
        return ret;
    }

    template <typename T, uint8_t Count>
    T BitUtils<T, Count>::extract(const T& in, const T& lo, const T& hi)
    {
#ifdef CHECK_INT_BOUNDS
        if (lo >= Count || hi >= Count)
            throw IndexOutOfBounds();
#endif
        T ret = 0;
        for (T i = lo; i <= hi; ++i)
        {
            const T p = 1 << i;
            if (in & p)
                ret |= 1 << (i - lo);
        }
        return ret;
    }

    template <typename T, uint8_t Count>
    bool BitUtils<T, Count>::getBit(const T& bits, const T& index)
    {
#ifdef CHECK_INT_BOUNDS
        if (index >= Count)
            throw IndexOutOfBounds();
#endif
        return (bits & 1 << index) != 0;
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::setBit(T& bits, const T& index)
    {
#ifdef CHECK_INT_BOUNDS
        if (index >= Count)
            throw IndexOutOfBounds();
#endif
        bits |= 1 << index;
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::assignBit(T& bits, const T& index)
    {
#ifdef CHECK_INT_BOUNDS
        if (index >= Count)
            throw IndexOutOfBounds();
#endif
        bits = (T)(1 << index);
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::clearBit(T& bits, const T& index)
    {
#ifdef CHECK_INT_BOUNDS
        if (index >= Count)
            throw IndexOutOfBounds();
#endif
        bits &= ~(1 << index);
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::applyBit(T& bits, const T& index, const bool value)
    {
        value ? setBit(bits, index) : clearBit(bits, index);
    }

    template <typename T, uint8_t Count>
    void BitUtils<T, Count>::printBit(const T& bits)
    {
        OutputStringStream os;

        const size_t v = (size_t)bits;

        std::bitset<Count> b(v);
        os << b << ' ' << '|' << ' ' << v;
        Console::writeLine(os);
    }

    using B8  = BitUtils<uint8_t, 8>;
    using B16 = BitUtils<uint16_t, 16>;

    namespace Gates
    {
        inline bool NAnd(const bool a, const bool b)
        {
            return !(a && b);
        }

        inline bool Not(const bool a)
        {
            return NAnd(a, a);
        }

        inline bool And(const bool a, const bool b)
        {
            const bool c = NAnd(a, b);
            return NAnd(c, c);
        }

        inline bool And3(const bool a, const bool b, const bool c)
        {
            return And(a, And(b, c));
        }

        inline bool Or(const bool a, const bool b)
        {
            return NAnd(Not(a), Not(b));
        }

        inline bool Or3(const bool a, const bool b, const bool c)
        {
            return Or(a, Or(b, c));
        }

        inline bool NOr(const bool a, const bool b)
        {
            return Not(NAnd(Not(a), Not(b)));
        }

        inline bool XOr(const bool a, const bool b)
        {
            const bool c = NAnd(a, b);
            return NAnd(NAnd(a, c), NAnd(c, b));
        }

        inline bool Mux(const bool a, const bool b, const bool s)
        {
            return Or(And(a, Not(s)), And(b, s));
        }

    }  // namespace Gates

    namespace BitwiseGates
    {
        template <typename T>
        T NAnd(const T& a, const T& b)
        {
            return ~(a & b);
        }

        template <typename T>
        T Not(const T& a)
        {
            return NAnd<T>(a, a);
        }

        template <typename T>
        T And(const T& a, const T& b)
        {
            return NAnd<T>(NAnd<T>(a, b), NAnd<T>(a, b));
        }

        template <typename T>
        T Or(const T& a, const T& b)
        {
            return NAnd<T>(Not<T>(a), Not<T>(b));
        }

        template <typename T>
        T NOr(const T& a, const T& b)
        {
            return Not<T>(NAnd<T>(NAnd<T>(a, a), NAnd<T>(b, b)));
        }

        template <typename T>
        T XOr(const T& a, const T& b)
        {
            T c = NAnd<T>(a, b);
            return NAnd<T>(NAnd<T>(a, c), NAnd<T>(c, b));
        }

        template <typename T>
        T Mux(const T& a, const T& b, const T& s)
        {
            return Or<T>(And<T>(a, Not<T>(s)), And<T>(b, s));
        }

    }  // namespace BitwiseGates

}  // namespace Hack::Chips
