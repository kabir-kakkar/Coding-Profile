#include <stdio.h>
#include <stdlib.h>

void scanArr (int arr[][10], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void printArr (int arr[][10], int m, int n)
{
    int i, j;
    printf("\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}
void transposeOfMatrix (int transpose[10][10], int arr[][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }
}
void multiply(int m1, int m2, int mat1[10][10],
            int n1, int n2, int mat2[10][10], int res[10][10])
{
    int x, i, j;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            res[i][j] = 0;
            for (x = 0; x < m2; x++)
            {
               res[i][j] += mat1[i][x] * mat2[x][j];
            }
        }
    }
}
int main()
{
    int arr[10][10], trans[10][10], res[10][10];
    int m1, m2, n1, n2;

    int i, j, k;

    scanf("%d", &m1);
    scanf("%d", &m2);

    // transpose condition
    n1 = m2;
    n2 = m1;

    scanArr(arr, m1, m2);
    printArr(arr, m1, m2);

    transposeOfMatrix(trans, arr, m1, m2);
    printArr(trans, n1, n2);

    multiply(m1, m2, arr, n1, n2, trans, res);
    printArr(res, m1, n2);
    return 0;
}
