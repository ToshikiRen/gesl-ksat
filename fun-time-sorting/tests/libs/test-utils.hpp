#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdbool>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>


#include "heap.h"
#include "utils.h"
#include "catch.hpp"

// Data for tests
#define TASK1_TEST_FILENAME "../data/test1-data.txt"


//Answer for tests
#define TASK1_TEST_SOLUTION1 "../data/checker/test1-solution.txt"


std::vector<int> beforeEach(const char *);
Heap *heapsortSetUp(const char *);