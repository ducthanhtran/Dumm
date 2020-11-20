#ifndef ATTACKS_HPP
#define ATTACKS_HPP

#include "bitboard.hpp"
#include <array>

enum Color {WHITE, BLACK};

template<Color color>
constexpr Bitboard pawn_attacks(Bitboard pawns)
{
    if constexpr(color == WHITE)
    {
        return shiftNorth(shiftEast(pawns)) | shiftNorth(shiftWest(pawns));
    }
    else
    {
        return shiftSouth(shiftEast(pawns)) | shiftSouth(shiftWest(pawns));
    }
}

constexpr Bitboard king_attacks(Bitboard king)
{
    auto attacks = shiftWest(king) | shiftEast(king);
    king |= attacks;
    attacks |= shiftNorth(king) | shiftSouth(king);
    return attacks;
}

constexpr Bitboard knight_attacks(Bitboard knight)
{
    const auto east = shiftEast(knight);
    const auto west = shiftWest(knight);
    const auto eastWest = east | west;
    auto attacks = shiftNorth(shiftNorth(eastWest)) | shiftSouth(shiftSouth(eastWest));

    const auto eastEast = shiftEast(east);
    const auto westWest = shiftWest(west);
    const auto doubleEastWest = eastEast | westWest;
    attacks |= shiftNorth(doubleEastWest) | shiftSouth(doubleEastWest);
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
constexpr std::array<Bitboard, 64> knightAttacks = populate_attacks(knight_attacks);
constexpr std::array<Bitboard, 64> whitePawnAttacks = populate_attacks(pawn_attacks<WHITE>);
constexpr std::array<Bitboard, 64> blackPawnAttacks = populate_attacks(pawn_attacks<BLACK>);

#endif