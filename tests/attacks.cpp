#include "doctest.h"
#include "bitboard.hpp"
#include "attacks.hpp"

TEST_CASE("KingAttack")
{
    for (auto squareIt = SquareIter(); *squareIt != SquareIter::end(); ++squareIt)
    {
        const auto [index, square] = *squareIt;

        auto trueKingAttack = UINT64_C(0);
        trueKingAttack |= shiftWest(square);
        trueKingAttack |= shiftNorthWest(square);
        trueKingAttack |= shiftNorth(square);
        trueKingAttack |= shiftNorthEast(square);
        trueKingAttack |= shiftEast(square);
        trueKingAttack |= shiftSouthEast(square);
        trueKingAttack |= shiftSouth(square);
        trueKingAttack |= shiftSouthWest(square);
        
        REQUIRE_EQ(kingAttacks[index], trueKingAttack);
    }
}

TEST_CASE("KnightAttack")
{
    for (auto squareIt = SquareIter(); *squareIt != SquareIter::end(); ++squareIt)
    {
        const auto [index, square] = *squareIt;

        const auto doubleNorth = shiftNorth(shiftNorth(square));
        const auto doubleEast = shiftEast(shiftEast(square));
        const auto doubleSouth = shiftSouth(shiftSouth(square));
        const auto doubleWest = shiftWest(shiftWest(square));

        auto trueKnightAttack = UINT64_C(0);
        trueKnightAttack |= shiftWest(doubleNorth);
        trueKnightAttack |= shiftEast(doubleNorth);

        trueKnightAttack |= shiftNorth(doubleEast);
        trueKnightAttack |= shiftSouth(doubleEast);

        trueKnightAttack |= shiftWest(doubleSouth);
        trueKnightAttack |= shiftEast(doubleSouth);
        
        trueKnightAttack |= shiftNorth(doubleWest);
        trueKnightAttack |= shiftSouth(doubleWest);
        
        REQUIRE_EQ(knightAttacks[index], trueKnightAttack);
    }
}