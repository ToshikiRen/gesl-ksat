#include "happy_print.h"

binaryTree* insertNode(binaryTree* root, int value)
{
    if(root == NULL)
    {
        binaryTree* node = (binaryTree*)malloc(sizeof(binaryTree));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
            
        return node;
    }
    
    if(value < root->value)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

void inorder(binaryTree* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int computeHeight(binaryTree *root)
{
    if(root == NULL)
        return -1;
    else
    {
        int maxLeft = computeHeight(root->left);
        int maxRight = computeHeight(root->right);

        return maxRight > maxLeft ? maxRight +1 : maxLeft + 1;

    }
}

queue* createQueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enQueue(queue* q, binaryTree* node, int level)
{
    if(q == NULL)
        return;
    
    qNode* nodeQ = (qNode*)malloc(sizeof(qNode));
    nodeQ->node = node;
    nodeQ->level = level;
    nodeQ->next = NULL;

    if(q->head == NULL && q->tail == NULL)
    {
        q->head = nodeQ;
        q->tail = nodeQ;    
    }
    else
    {
        q->tail->next = nodeQ;
        q->tail = nodeQ;
    }
    
}

qNode* deQueue(queue* q)
{
    if(q == NULL)
        return NULL;
    qNode* returnNode;
    returnNode = q->head;
    if(q->head == q->tail)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    else 
        q->head = q->head->next;    
 
    return returnNode;
}

int isNotEmpty(queue* q)
{
    if(q->head == NULL)
        return 0;
    return 1;
}

void populateSpacesAndDelimiters(int maxHeight, int* spaces, int* delimiters)
{
    int i;
    delimiters[maxHeight] = 4;
    spaces[maxHeight] = 0;

    for(i = maxHeight - 1; i >= 0; i--)
    {
        spaces[i] = spaces[i + 1] + delimiters[i + 1] + 3;
        delimiters[i] = (delimiters[i + 1] + 1) * 2;
    }

}

void printCaracter(char character, int number)
{
    int i;
    for(i = 0; i < number; i++)
    {
        printf("%c", character);
    }
}

void happyPrint(binaryTree* root)
{
    queue* q = createQueue();
    qNode* queueNode = NULL;
    binaryTree* dummyNode;
    int height = computeHeight(root);
    int *spaces, *delimiters, lastLevel = -1;

    spaces = (int*)malloc(sizeof(int)*(height + 1));
    delimiters = (int*)malloc(sizeof(int)*(height + 1));

    populateSpacesAndDelimiters(height, spaces, delimiters);

    dummyNode = (binaryTree*)malloc(sizeof(binaryTree));
    dummyNode->value = INT_MIN;
    dummyNode->left = NULL;
    dummyNode->right = NULL;

    enQueue(q, root, 0);


    while(isNotEmpty(q)) 
    {
        queueNode = deQueue(q);
        if(queueNode->node->left)
            enQueue(q, queueNode->node->left, queueNode->level + 1);
        else if(queueNode->level + 1 <= height)
            enQueue(q, dummyNode, queueNode->level + 1);


        if(queueNode->node->right)
            enQueue(q, queueNode->node->right, queueNode->level + 1);
        else if(queueNode->level + 1 <= height)
            enQueue(q, dummyNode, queueNode->level + 1);

        // dummy node
        if(lastLevel != queueNode->level)
            printf("\n");
        if(queueNode->node->value == INT_MIN)
        {
            if(lastLevel != queueNode->level)
                printCaracter(' ', spaces[queueNode->level]);
            printCaracter('_', delimiters[queueNode->level]);
            printf("xxx");
            printCaracter('_', delimiters[queueNode->level]);
            if(queueNode->level > 0)
            {
                printCaracter(' ', 2 * (delimiters[queueNode->level - 1] - delimiters[queueNode->level]) + 3);
            }
        }
        else
        {
            if(lastLevel != queueNode->level)
                printCaracter(' ', spaces[queueNode->level]);
            printCaracter('_', delimiters[queueNode->level]);
            printf("%3d", queueNode->node->value);
            printCaracter('_', delimiters[queueNode->level]);
            if(queueNode->level > 0)
            {
                printCaracter(' ', 2 * (delimiters[queueNode->level - 1] - delimiters[queueNode->level]) + 3);
            }
        }

        lastLevel = queueNode->level;
        
    }

    free(spaces);
    free(delimiters);
}

