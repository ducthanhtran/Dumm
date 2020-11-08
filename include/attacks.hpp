#ifndef ATTACKS_HPP
#define ATTACKS_HPP

#include "bitboard.hpp"
#include <array>

constexpr Bitboard king_attacks(Bitboard king)
{
    auto attacks = shiftWest(king) | shiftEast(king);
    king |= attacks;
    attacks |= shiftNorth(king) | shiftSouth(king);
    return attacks;
}

template<typename AttackGenerator>
constexpr std::array<Bitboard, 64> populate_attacks(AttackGenerator &attackGen)
{
    std::array<Bitboard, 64> attacks = {};
    for(auto squareIt = SquareIter(); *squareIt != SquareIter::end(); ++squareIt)
    {
        const auto [index, square] = *squareIt;
        attacks[index] = attackGen(square);
    }
    return attacks;
}

constexpr std::array<Bitboard, 64> kingAttacks = populate_attacks(king_attacks);

#endif