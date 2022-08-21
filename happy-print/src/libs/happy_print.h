#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct binaryTree 
{
    int value;
    struct binaryTree* right;
    struct binaryTree* left;
}binaryTree; 

typedef struct queueNode
{
    binaryTree* node; 
    int level;

    struct queueNode* next;

}qNode;


typedef struct
{
    qNode* head;
    qNode* tail;
}queue;

binaryTree* insertNode(binaryTree* , int );
void inorder(binaryTree* );
int computeHeight(binaryTree*);
queue* createQueue();
void enQueue(queue* , binaryTree* , int );
qNode* deQueue(queue* );
int isNotEmpty(queue* );
void populateSpacesAndDelimiters(int , int* , int* );
void printCaracter(char , int );
void happyPrint(binaryTree* );
