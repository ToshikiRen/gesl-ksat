#include "catch.hpp"
#include "utils.h"
#include "test-utils.hpp"
#include "heap.h"

TEST_CASE("FUN TIME SORTING") {
    
    SECTION("Heapsort") {
		std::vector<int> data = beforeEach(TASK1_TEST_SOLUTION1);
		Heap *h = heapsortSetUp(TASK1_TEST_FILENAME);
        REQUIRE(h != NULL);
        for (unsigned int i = 0; i < data.size(); i++) {
            REQUIRE(data.at(i) == h->vec[i]);
        }
        deleteHeap(&h);
    }
}

