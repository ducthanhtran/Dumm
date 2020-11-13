#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <cstdint>
#include <utility>

using Bitboard = std::uint64_t;

// Using little-endian rank-file mapping
constexpr Bitboard A_FILE = UINT64_C(0x8080808080808080);
constexpr Bitboard H_FILE = UINT64_C(0x0101010101010101);
constexpr Bitboard NOT_A_FILE = ~A_FILE;
constexpr Bitboard NOT_H_FILE = ~H_FILE;

constexpr Bitboard SQUARE_A1 = UINT64_C(0x8000000000000000);
constexpr Bitboard SQUARE_H8 = UINT64_C(0x1);

constexpr Bitboard shiftNorth(Bitboard bitset) { return bitset >> 8; }
constexpr Bitboard shiftNorthEast(Bitboard bitset) { return bitset >> 9 & NOT_A_FILE; }
constexpr Bitboard shiftEast(Bitboard bitset) { return bitset >> 1 & NOT_A_FILE; }
constexpr Bitboard shiftSouthEast(Bitboard bitset) { return bitset << 7 & NOT_A_FILE; }
constexpr Bitboard shiftSouth(Bitboard bitset) { return bitset << 8; }
constexpr Bitboard shiftSouthWest(Bitboard bitset) { return bitset << 9 & NOT_H_FILE; }
constexpr Bitboard shiftWest(Bitboard bitset) { return bitset << 1 & NOT_H_FILE; }
constexpr Bitboard shiftNorthWest(Bitboard bitset) { return bitset >> 7 & NOT_H_FILE; }

class SquareIter
{
    public:
        constexpr SquareIter() : m_square(SQUARE_A1), m_index(0) {}
        constexpr static std::pair<std::uint8_t, Bitboard> begin() { return std::pair(0, SQUARE_A1); }
        constexpr static std::pair<std::uint8_t, Bitboard> end() { return std::pair(64, UINT64_C(0)); }
        constexpr SquareIter& operator++()
        {
            if (std::pair(m_index, m_square) != SquareIter::end())
            {
                m_square >>= 1;
                ++m_index;
            }
            return *this;
        }
        constexpr SquareIter operator++(int)
        {
            SquareIter temp(*this);
            ++(*this);
            return temp;
        }
        constexpr bool operator!=(const SquareIter& rhs) const { return m_index != rhs.m_index; }
        constexpr bool operator==(const SquareIter& rhs) const { return m_index == rhs.m_index; }
        constexpr std::pair<std::uint8_t, Bitboard> operator*() const { return std::pair(m_index, m_square); }
    private:
        Bitboard m_square;
        std::uint8_t m_index;
};

#endif