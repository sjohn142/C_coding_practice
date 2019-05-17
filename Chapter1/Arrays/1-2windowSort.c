#include <stdio.h>
#include <stdlib.h>

// Given an array of integers our of order, determine bounds of smaller window that must be sorted
// in order for entire array to be sorted -- USING ASCENDING
// What to return on error? What if the array is sorted?

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

// NAIVE: Sort entire array. See which indexes are different. Return range of indexes that changed.
void naiveBounds(int *array, int size)
{
    int min = -1;
    int max  = 0;
    int arrayC[size];
    for (int i=0; i<size; i++)
    {
        arrayC[i] = array[i];
    }
    qsort(arrayC, size, sizeof(int), cmpfunc);
 
    for (int i=0; i<size;i++)
    {
        if (arrayC[i] != array[i])
        {
            if (min == -1)
            {
                min = i;
            }
            else if (i > max)
            {
                max = i;
            }
        }
    }
    printf("(%i, %i)\n", min, max);
}

// COMPLEX:

int main()
{
    int list1[5] = {3, 7, 5, 6, 9};
    int list2[4] = {5, 2, 1, 8};
    int list3[4] = {8, 5, 1, 2};
    int list4[6] = {1, 2, 4, 5, 6, 8};

    naiveBounds(list1, 5);
    naiveBounds(list2, 4);
    naiveBounds(list3, 4);
    naiveBounds(list4, 6);
}