#include "happy_print.h"

int main()
{
    binaryTree* root = insertNode(NULL, 100);
    insertNode(root, 120);
    insertNode(root, 42);
    insertNode(root, 20);
    insertNode(root, 50);
    insertNode(root, 500);
    insertNode(root, 490);
    happyPrint(root);

    return 0;
}