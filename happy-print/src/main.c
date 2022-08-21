#include "happy_print.h"


int main()
{
    binaryTree* root = NULL;

    root = insertNode(root, 100);
    
    insertNode(root, 123);
    insertNode(root, 433);
    insertNode(root, 642);
    //insertNode(root, 842);
    //insertNode(root, 942);
    //insertNode(root, 999);
    //inorder(root);
    happyPrint(root);

    return 0;
}