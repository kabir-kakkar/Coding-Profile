#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[4][4] = { {1, 0, 0}, {1, 1, 1}, {0, 1, 1}, {1, 1, 0} };

    int m = 4, n = 3;
    int i, j, k;
    int row=0, col=0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                row++;
        }
        printf("\n the number of ones in row %d is %d", i, row);
        row = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[j][i] == 1)
                col++;
        }
        printf("\n the number of ones is column %d is %d", i, col);
        col = 0;
    }

    return 0;
}
