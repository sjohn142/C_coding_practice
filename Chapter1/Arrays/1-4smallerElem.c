#include <stdio.h>

void findSmaller(int *array, int size)
{
    int array2[size];
    for (int i=0; i<size; i++)
    {
        int count = 0;
        for (int j=i+1; j<size; j++)
        {
            if (array[j] < array[i])
            {
                count++;
            }
        }
        array2[i] = count;
    }

    printf("(%i, ", array2[0]);
    for (int i=1; i<size-1; i++)
    {
        printf("%i, ", array2[i]);
    }
    printf("%i)\n", array2[size-1]);
}

int main()
{
    int list1[5] = {3, 4, 9, 6, 1};
    int list2[6] = {8, 40, 3, 100, 6, 1};

    findSmaller(list1, 5);
    findSmaller(list2, 6);
}