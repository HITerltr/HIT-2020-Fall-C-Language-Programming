#include <stdio.h>
#include <stdlib.h>
int max(int **D, int m, int n, int *pmax_i, int *pmax_j);
int main()
{
    int m, n;
    printf("Please input m and n(the number of rows and columns):");
    scanf("%d%d", &m, &n);

    int **D;
    D = (int **)malloc(m * sizeof(int *));
    int i, j;
    for (i = 0; i < m; i ++)
        D[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < m; i ++)
        for (j = 0; j < n; j ++)
            D[i][j] = rand();

    for (i = 0; i < m; i ++){
        for (j = 0; j < n; j ++)
            printf("%d ", D[i][j]);
        printf("\n");
    }

    int max_value;
    int max_i, max_j;
    max_value = max(D, m, n, &max_i, &max_j);

    printf("The maximum value is %d at (%d, %d).\n", max_value, max_i, max_j);

    for (i = 0; i < m; i ++)
        free(D[i]);
    free(D);
    return 0;
}
int max(int **D, int m, int n, int *pmax_i, int *pmax_j)
{
    int max_value = D[0][0];
    int i, j;
    for (i = 0; i < m; i ++)
        for (j = 0; j < n; j ++)
            if (max_value < D[i][j]){
                max_value = D[i][j];
                *pmax_i = i;
                *pmax_j = j;
            }
    return max_value;
}
