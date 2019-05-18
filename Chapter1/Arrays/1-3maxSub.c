#include <stdio.h>

int sum(int *array, int leftIndex, int rightIndex)
{
    int totalSum = 0;
    int minVal = 0;
    int minIndex = 0;
    for (int i=leftIndex; i<rightIndex; i++)
    {
        totalSum += array[i];
    }

    for (int i=leftIndex; i<rightIndex; i++)
    {
        if (array[i] < minVal)
        {
            minVal = array[i];
            minIndex = i;
        }
    }

    if (minVal != 0) {
        int rightSum = sum(array, minIndex+1, rightIndex);
        int leftSum = sum(array, leftIndex, minIndex-1);
        if (rightSum > totalSum)
        {
            totalSum = rightSum;
        }
        if (leftSum > totalSum)
        {
            totalSum = leftSum;
        }
    }
    return totalSum;
}

int main()
{
    int list1[6] = {34, -50, 42, 14, -5, 86};
    int maxSum = sum(list1, 0, 6);
    printf("%i\n", maxSum);
}