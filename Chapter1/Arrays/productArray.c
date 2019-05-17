#include <stdio.h>

int *arrayProduct(int *array, int size)
{
    int sumlist[size];
    int sum = 1;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++){
            if (j != i)
            {
                sum = sum * array[j];
            }
        }
        sumlist[i] = sum;
        sum = 1;
    }
    array = sumlist;
    return array;
}

int main()
{
    int list[5] = {1, 2, 3, 4, 5};
    int *output = arrayProduct(list, 5);
    for (int i=0; i<5; i++){
        printf("%i\n", output[i]);
    }
}