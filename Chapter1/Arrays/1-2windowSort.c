#include <stdio.h>
#include <stdlib.h>

// NAIVE METHOD: Compare each digit in the array to see if it is in the right place, marking
// where the smallest and largest values should be.
void naiveBounds(int *array, int size)
{
    int minIndex = -1;
    int maxIndex = -1;

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (array[i] > array[j])
            {
                if (minIndex == -1)
                {
                    minIndex = i;
                }
            }
        }
    }

    for (int i=size-1; i>=0; i--)
    {
        for (int j=i-1; j>=0; j--)
        {
            if (array[i] < array[j])
            {
                if (maxIndex == -1)
                {
                    maxIndex = i;
                }
            }
        }
    }
    if (minIndex == -1)
    {
        printf("The array is already sorted.\n");
    }
    else
    {
        printf("(%i, %i)\n", minIndex, maxIndex);
    }
}

// NON-NAIVE
void nBounds(int *array, int size)
{
    int currMax = 0;
    int maxIndex = 0;
    int minIndex = 0;
    // find max
    for (int i=0; i<size; i++)
    {
        if (array[i] > currMax)
        {
            currMax = array[i];
        }
        if (array[i] < currMax)
        {
            maxIndex = i;
        }
    }
    // find min
    int currMin = currMax;
    for (int i=size-1; i>=0; i--)
    {
        if (array[i] < currMin)
        {
            currMin = array[i];
        }
        if (array[i] > currMin)
        {
            minIndex = i;
        }
    }

    printf("(%i, %i)\n", minIndex, maxIndex);
}

int main()
{
    int list1[5] = {3, 7, 5, 6, 9};
    int list2[4] = {5, 2, 1, 8};
    int list3[4] = {8, 5, 1, 2};
    int list4[6] = {1, 2, 4, 5, 6, 8};
    int list5[7] = {1, 4, 2, 7, 3, 5, 9};
    int list6[7] = {3, 4, 2, 7, 1, 5, 9};
    int list7[7] = {1, 4, 2, 7, 9, 3, 5};
    int list8[5] = {1, 2, 4, 7, 5};

    printf("NAIVE:\n");
    naiveBounds(list1, 5);
    naiveBounds(list2, 4);
    naiveBounds(list3, 4);
    naiveBounds(list4, 6);
    naiveBounds(list5, 7);
    naiveBounds(list6, 7);
    naiveBounds(list7, 7);
    naiveBounds(list8, 5);

    printf("NON-NAIVE:\n");

    nBounds(list1, 5);
    nBounds(list2, 4);
    nBounds(list3, 4);
    nBounds(list4, 6);
    nBounds(list5, 7);
    nBounds(list6, 7);
    nBounds(list7, 7);
    nBounds(list8, 5);
}