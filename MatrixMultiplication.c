#include <stdio.h>
#include <stdlib.h>

int **allocate(int m, int n);
void freep(int **M, int m);
void inputMatrix(FILE *fp, int **A, int m, int n);
void outputMatrix(FILE *fp, int **M, int m, int n);
void multiply(int **A, int **B, int m, int n, int p, int **C);

int main()
{
    FILE *fp1 = fopen("E:\\courses\\C\\chapter8\\MatrixMultiplication1\\m1.txt", "r");
    if (fp1 == NULL){
        printf("Open file error!\n");
        exit(1);
    }

    FILE *fp2 = fopen("E:\\courses\\C\\chapter8\\MatrixMultiplication1\\m2.txt", "r");
    if (fp2 == NULL){
        printf("Open file error!\n");
        exit(1);
    }

    FILE *fp3 = fopen("E:\\courses\\C\\chapter8\\MatrixMultiplication1\\m3.txt", "w");
    if (fp3 == NULL){
        printf("Open file error!\n");
        exit(1);
    }

    int m, n, p;
    fscanf(fp1, "%d%d", &m, &n);
    fscanf(fp2, "%*d%d", &p);


    int **A = allocate(m, n);
    int **B = allocate(n, p);
    int **C = allocate(m, p);

    inputMatrix(fp1, A, m, n);
    inputMatrix(fp2, B, n, p);
    multiply(A, B, m, n, p, C);
    outputMatrix(fp3, C, m, p);
    freep(A, m);
    freep(B, n);
    freep(C, m);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}

int **allocate(int m, int n)
{
     int **A = (int **)malloc(m * sizeof(int *));
    int i;
    for (i = 0; i < m; i ++)
        A[i] = (int *)malloc(n * sizeof(int));
    return A;
}
void freep(int **M, int m)
{
    int i, j;
    for (i = 0; i < m; i ++){
        free(M[i]);
    }
    free(M);
}

void inputMatrix(FILE *fp, int **A, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i ++){
        for (j = 0; j < n; j ++)
            fscanf(fp, "%d ", &A[i][j]);
    }
}

void outputMatrix(FILE *fp, int **M, int m, int n)
{
    fprintf(fp, "%d %d\n", m, n);
    int i, j;
    for (i = 0; i < m; i ++){
        for (j = 0; j < n; j ++)
            fprintf(fp, "%d ", M[i][j]);
        fprintf(fp,"\n");
    }
}

void multiply(int **A, int **B, int m, int n, int p, int **C)
{
    int i, j, k;
    for (i = 0; i < m; i ++)
        for (j = 0; j < p; j ++) {
            C[i][j] = 0;
            for (k = 0; k < n; k ++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
