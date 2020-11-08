#include "doctest.h"
#include "bitboard.hpp"

TEST_CASE("SquareIter")
{
    SquareIter s;
    REQUIRE_EQ(*s, SquareIter::begin());
    
    SUBCASE("Pre-increment")
    {
        ++s;
        REQUIRE_NE(*s, SquareIter::begin());
        for (auto i = 1; i <= 63; ++i)
        {
            ++s;
        }
        REQUIRE_EQ(*s, SquareIter::end());
        ++s;
        REQUIRE_EQ(*s, SquareIter::end());
    }

    SUBCASE("Post-increment")
    {
        s++;
        REQUIRE_NE(*s, SquareIter::begin());
        for (auto i = 0; i < 63; ++i)
        {
            s++;
        }
        REQUIRE_EQ(*s, SquareIter::end());
        s++;
        REQUIRE_EQ(*s, SquareIter::end());
    }
}