#include "next-permutation.h"

void numberToVector(int number, int **vector, int *numberLen)
{
    int numberOfLetters = 0, tempNumber = number;
    while(tempNumber > 0)
    {
        numberOfLetters++;
        tempNumber = tempNumber/10;
    }
    *numberLen = numberOfLetters;
    *vector = (int*)malloc(numberOfLetters * sizeof(int));

    while(number > 0)
    {
        (*vector)[numberOfLetters - 1] = number%10;
        number /= 10;
        numberOfLetters--;
    }

}


void reverseVector(int *vector, int start, int end)
{
    int i = start;
    int tempValue;
    for(i = start; i < (start + end)/2 + 1; i++)
    {
        tempValue = vector[i];
        vector[i] = vector[start + end - i];
        vector[start + end - i] = tempValue;
    }
}
int toNumber(int *vector, int vectorSize)
{
    int number = 0, i;
    for(i = 0; i < vectorSize; i++)
        number = number*10 + vector[i];

    return number;

}
int next_permutation(int number)
{
    int *vector, vectorSize;
    numberToVector(number, &vector, &vectorSize);
    int i = vectorSize - 2;

    int firstIndex, secondIndex, tempLetter;

    while(i >= 0 && vector[i] >= vector[i + 1])
        i--;
    firstIndex = i;
    

    if(firstIndex >= 0)
    {
        i = vectorSize - 1;
        while(vector[firstIndex] >= vector[i])
            i--; 
        secondIndex = i;

        tempLetter = vector[firstIndex];
        vector[firstIndex] = vector[secondIndex];
        vector[secondIndex] = tempLetter;

        reverseVector(vector, firstIndex + 1, vectorSize - 1);
    }
    else
        reverseVector(vector, 0, vectorSize - 1);
    
    return toNumber(vector, vectorSize);
}