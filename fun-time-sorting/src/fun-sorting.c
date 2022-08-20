#include "heap.h"

void readVector(int **v, int vectorSize, FILE *input)
{

	int i;
	*v = (int *)calloc(vectorSize, sizeof(int));

	for (i = 0; i < vectorSize; i++)
		fscanf(input, "%d", &(*v)[i]);
}


void heapsort(Heap *h, int *buffer, int bufferSize)
{
    if(h == NULL || buffer == NULL || bufferSize == 0)
        return;
    
    populateHeap(h, buffer, bufferSize);

    int i, tempNode;

    for(i = bufferSize - 1; i >= 0; i--) 
    {
        tempNode = h->vec[0];
        h->vec[0] = h->vec[i];
        h->vec[i] = tempNode;
        h->size--;
        heapify(h, 0);
    }

    h->size = bufferSize;

    FILE* f = fopen("result.txt", "w");
    printHeapInFile(h, f);


}