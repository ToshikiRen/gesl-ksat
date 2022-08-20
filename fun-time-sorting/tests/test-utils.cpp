#include "test-utils.hpp"


std::vector<int> beforeEach(const char * test_task_data)
{
		
	std::ifstream file(test_task_data);
	
	std::vector<int> sortedVector;
	int size, element;
	file >> size;
	
	for (int i = 0; i < size; i++) {
		file >> element;
		sortedVector.push_back(element);
	}
	
	return sortedVector;
}


Heap *heapsortSetUp(const char * test_task_data) {
	
	FILE *f = openFile(test_task_data, READ_MODE);
	REQUIRE(isNotNull(f));
	
	int size;
	Heap *h;
	
	fscanf(f, "%d", &size);
	h = create(size);
	REQUIRE(isNotNull(h));
	
	int *vector = NULL;
	readVector(&vector, size, f);
	REQUIRE(isNotNull(vector));
	
	heapsort(h, vector, size);
	REQUIRE(isNotNull(h->vec));
	return h;
}
