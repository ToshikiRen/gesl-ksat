#include "test-utils.hpp"


std::vector<int> beforeEach(const char * test_task_data)
{
		
	std::ifstream file(test_task_data);
	
	std::vector<int> vector;
	int size, element;
	file >> size;
	
	for (int i = 0; i < size; i++) {
		file >> element;
		vector.push_back(element);
	}
	
	return vector;
}

