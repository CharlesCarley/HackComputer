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
#include "Chips/BitUtils.h"
#include "Utils/Console.h"

namespace Hack::Chips
{
    /// <summary>
    /// Chip is the base class for all chips defined in this system.
    /// It uses a template integer for the <b>_bits</b> member variable.
    /// Most chips should maintain a cache bit (usually the MSB) to
    /// control evaluation.
    /// Evaluation happens as follows:
    ///  1. If the input of the chip is modified mark the cache bit.
    ///  2. Any call to query an output should check this bit.
    ///     a. If it is set call evaluate then return the output.
    ///     b. If it is not set then return the output.
    /// </summary>
    /// <typeparam name="T">
    /// Should be one of the uint8_t, uint16_t, uint32_t,
    /// uint64_t, bit16_t, bit32_t, or bit64_t integer types.
    /// </typeparam>
    /// <typeparam name="Count">
    /// Should reflect the total number of bits stored in T.
    /// </typeparam>
    template <typename T, uint8_t Count>
    class Chip
    {
    protected:
        /// <summary>
        /// This method should be used to update the state
        /// of the _bits member variable.
        /// </summary>
        virtual void evaluate();

        virtual bool isDirty();

        T _bits;

    public:
        Chip();

        virtual ~Chip() = default;

        /// <summary>
        /// Prints the binary and decimal representation
        /// of the current state of the _bits member.
        /// </summary>
        void print();

        /// <summary>
        /// Returns the state of the bit at the supplied index.
        /// </summary>
        bool getBit(const uint8_t& index);

        /// <summary>
        /// Sets the bit at the supplied index.
        /// </summary>
        void setBit(const uint8_t& index);

        /// <summary>
        /// Zeros all bits except for the bit at the supplied index.
        /// </summary>
        void assignBit(const uint8_t& index);

        /// <summary>
        /// Clears the bit at the supplied index.
        /// </summary>
        void clearBit(const uint8_t& index);

        /// <summary>
        /// Clears or sets the bit at the supplied index.
        /// </summary>
        /// <param name="index"></param>
        /// <param name="value">A value of true will set the bit.</param>
        void applyBit(const uint8_t& index, const bool value);
    };

    template <typename T, uint8_t Count>
    Chip<T, Count>::Chip() :
        _bits()
    {
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::evaluate()
    {
    }

    template <typename T, uint8_t Count>
    bool Chip<T, Count>::isDirty()
    {
        return true;
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::print()
    {
#ifdef PRINT_CHIP_STATE
        if (isDirty())
            evaluate();
        BitUtils<T, Count>::printBit(_bits);
#endif
    }

    template <typename T, uint8_t Count>
    bool Chip<T, Count>::getBit(const uint8_t& index)
    {
        return BitUtils<T, Count>::getBit(_bits, index);
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::setBit(const uint8_t& index)
    {
        BitUtils<T, Count>::setBit(_bits, index);
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::assignBit(const uint8_t& index)
    {
        BitUtils<T, Count>::assignBit(_bits, index);
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::clearBit(const uint8_t& index)
    {
        BitUtils<T, Count>::clearBit(_bits, index);
    }

    template <typename T, uint8_t Count>
    void Chip<T, Count>::applyBit(const uint8_t& index, const bool value)
    {
        BitUtils<T, Count>::applyBit(_bits, index, value);
    }

}  // namespace Hack::Chips
