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