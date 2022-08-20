#include "catch.hpp"
#include "test-utils.hpp"
#include "next-permutation.h"

TEST_CASE("NEXT PERMUTATION") {
    
    SECTION("Testing next of 1234") {
		REQUIRE(next_permutation(1234) == 1243);
    }
    SECTION("Testing next of 2314") {
		REQUIRE(next_permutation(2314) == 2341);
    }
    SECTION("Testing next of 3241") {
		REQUIRE(next_permutation(3241) == 3412);
    }
    SECTION("Testing next of 1234") {
		REQUIRE(next_permutation(4231) == 4312);
    }
    
    SECTION("Testing complete permutations for number 123456") {
		std::vector<int> vector = beforeEach(TASK1_TEST_SOLUTION1);
        int i = 0;
        int currentNumber = 123456;
        REQUIRE(currentNumber == vector[0]);
        for(i = 1; i < 720; i++)
        {
            currentNumber = next_permutation(currentNumber);
            REQUIRE(vector[i] == currentNumber);
        }
    }
}

