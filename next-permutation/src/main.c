#include "next-permutation.h"

int main()
{
    int initialNumber = 1234;
    int currentNumber = next_permutation(initialNumber);
    printf("%d\n", initialNumber);
    while(currentNumber != initialNumber)
    {
        printf("%d\n", currentNumber);
        currentNumber = next_permutation(currentNumber);
    }
    
    return 0;
}