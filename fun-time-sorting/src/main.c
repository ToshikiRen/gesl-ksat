
#include "heap.h"
#include "utils.h"

#define USER_DEFINED_INPUT "..\\data\\user-defined-test-data.txt"
#define USER_DEFINED_OUTPUT "..\\data\\user-defined-test-data-program-output.txt"

int main()
{
	int *vector = NULL;
	int vectorSize;
	FILE* inputFile = openFile(USER_DEFINED_INPUT, READ_MODE);
	FILE *outputFile = openFile(USER_DEFINED_OUTPUT, WRITE_MODE);

	fscanf(inputFile, "%d", &vectorSize);
	readVector(&vector, vectorSize, inputFile);

	Heap *h = create(1);
	heapsort(h, vector, vectorSize);

	printHeapInFile(h, outputFile);
	

	return 0;
}