#include <stdio.h>

void findIndex(char *s, int sizeS, char *w, int sizeW)
{
    int j = 0;
    int startIndex = 0;

    for (int i=0; i<sizeS; i++)
    {
        if (s[i] == w[j])
        {
            if (j == 0)
            {
                startIndex = i;
                j++;
            }
            else if (j == (sizeW - 1))
            {
                printf("%i\n", startIndex);
                j = 0;
            }
            else
            {
                j++;
            }
        }
        else
        {
            j = 0;
        }
    }

    j = 0;
    for (int i=sizeS-1; i>=0; i--)
    {
        if (s[i] == w[j])
        {
            if (j == 0)
            {
                startIndex = i;
                j++;
            }
            else if (j == (sizeW - 1))
            {
                printf("%i\n", startIndex);
                j = 0;
            }
            else
            {
                j++;
            }
        }
        else
        {
            j = 0;
        }
    }
}

int main()
{
char s[8]= "axabxaba";
char w[2] = "ab";

findIndex(s, 8, w, 2);

}
