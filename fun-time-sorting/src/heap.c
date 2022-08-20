#include "heap.h"


Heap *create(int capacity)
{
	Heap *h = (Heap *)malloc(sizeof(Heap));

	if (!h)
	{
		printf("Space could not be allocated");
		return NULL;
	}
	h->size = 0; // Initial heap-ul este gol
	h->capacity = capacity;

	h->vec = (int *)calloc(capacity, sizeof(int));
	if (!h->vec)
	{
		printf("Space could not be allocated");
		return NULL;
	}

	return h;
}

int leftChild(Heap *h, int i)
{
    int position = 2 * i  + 1;
    if(position >= h->size || i < 0)
        return -1;

    return position;
}

int rightChild(Heap *h, int i)
{
    int position = 2 * i + 2;
    if(position >= h->size || i < 0)
        return -1;
    
    return position;
}

void heapify(Heap *h, int i)
{
    int lChild, rChild, tempNode, maxPosition = i;

    lChild = leftChild(h, i);
    rChild = rightChild(h, i);

    if(rChild != -1 && h->vec[rChild] > h->vec[maxPosition])
        maxPosition = rChild;
    if(lChild != -1 && h->vec[lChild] > h->vec[maxPosition])
        maxPosition = lChild;

    while(maxPosition != i)
    {
        tempNode = h->vec[maxPosition];
        h->vec[maxPosition] = h->vec[i];
        h->vec[i] = tempNode;
        
        i = maxPosition;

        lChild = leftChild(h, i);
        rChild = rightChild(h, i);

        if(rChild != -1 && h->vec[rChild] > h->vec[maxPosition])
            maxPosition = rChild;
        if(lChild != -1 && h->vec[lChild] > h->vec[maxPosition])
            maxPosition = lChild;
    }
}

void resize(Heap *h)
{
    int *tempHeapVector = (int*) realloc(h->vec, h->capacity * 2); 
    
    if(tempHeapVector != NULL)
    {
        h->vec = tempHeapVector;
        h->capacity *= 2;
    }
    else
    {
        printf("Space could not be reallocated");
        return;
    }

}


void deleteHeap(Heap **h)
{
    if(h != NULL)
    {
       if(*h != NULL)
       {
        if((*h)->vec != NULL)
            free((*h)->vec);
        free((*h));
        *h = NULL;
       }
    }
}


void populateHeap(Heap *h, int *buffer, int bufferSize)
{
    if(h == NULL || buffer == NULL || bufferSize == 0)
        return;
    
    while(bufferSize > h->capacity)
        resize(h);

    int i = 0;

    for(i = 0; i < bufferSize; i++)
        h->vec[i] = buffer[i];
    h->size = bufferSize;

    for(i = (bufferSize - 1) / 2; i >= 0; i--)
        heapify(h, i);
}

void printHeapInFile(Heap *h, FILE *output)
{
	int i;
	fprintf(output, "%d\n", h->size);
	for (i = 0; i < h->size; i++)
		fprintf(output, "%d ", h->vec[i]);
	fprintf(output, "\n");
}
