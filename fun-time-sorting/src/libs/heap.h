#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int *vec; 
    int size, capacity;

}Heap;


Heap* create(int );
int leftChild(Heap *, int );
int rightChild(Heap *, int );
void heapify(Heap *, int );
void resize(Heap *);
void deleteHeap(Heap **);
void printHeapInFile(Heap *, FILE *);
void populateHeap(Heap *, int *, int );

void readVector(int **, int , FILE* );
void heapsort(Heap *, int *, int );