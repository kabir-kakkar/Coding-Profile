#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(12 * sizeof(int)), index = 0;
    int A[4][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int i;

    for (i = 0; i < 4; i++)
    {
            p[index] = A[i][i];
            index++;
    }

    for (i = 0; i < 3; i++)
    {
        p[index] = A[i][i+1];
        index++;
    }

    for (i = 0; i < 3; i++)
    {
        p[index] = A[i+1][i];
        index++;
    }

    for (i = 0; i < 10; i++)
    {
        printf ("%d \t", *(p+i));
    }

}
