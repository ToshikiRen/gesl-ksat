#include "happy_print.h"


int main()
{
    binaryTree* root = NULL;

    root = insertNode(root, 100);
    
    insertNode(root, 123);
    insertNode(root, 433);
    //insertNode(root, 42);
    insertNode(root, 1242);
    //inorder(root);
    happyPrint(root);

    return 0;
}