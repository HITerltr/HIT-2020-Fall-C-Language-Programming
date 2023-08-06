#include <stdio.h>
#include <stdlib.h>
void sort(int v[], int n);
int main()
{
    int n = 0;
    int *p, *q;
    printf("Please input the numbers:\n");
    int size = 1;
    p = (int *)malloc(size * sizeof(int));
    int x;
    int i;
    while(scanf("%d", &x) == 1){
        n ++;
        if (n > size){
            size *= 2;
            q = p;
            p = (int *)malloc(size* sizeof(int));
            for(i = 0; i < n - 1; i ++)
                p[i] = q[i];
            free(q);
        }
        p[n-1] = x;
    }
    q = p;
    p = (int *)malloc(n* sizeof(int));
    for(i = 0; i < n; i ++)
        p[i] = q[i];
    free(q);
    sort(p, n);
    for(i = 0; i < n; i ++)
        printf("%d ", p[i]);
    free(p);
    return 0;
}
void sort(int v[], int n)
{
    int i, j, temp;
     for (i = 1; i < n; i ++){
        temp = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > temp){
            v[j+1] = v[j];
            j --;
        }
        v[j+1] = temp;
     }
}
