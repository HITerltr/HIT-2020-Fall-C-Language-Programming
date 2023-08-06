#include <stdio.h>
#include <stdlib.h>
void InputArray(int *p,int m,int n);
double Average(int *p,int m,int n);

int main(void)
{
    int *p=NULL,m,n;
    double aver;
    printf("How many Countries?");
    scanf("%d",&m);
    printf("How many students in a class?");
    scanf("%d",&n);
    if(p==NULL)
    {
              printf("No enough memory!\n");
              exit(1);
    }
    InputArray(p,m,n);
    aver=Average(p,m,n);
    printf("aver = %.1f\n",aver);
        return 0;
}
void InputArray(int *p,int m,int n)
{
          int i,j;
          for(i=0;i<m;i++)
          {
                    printf("Please enter scores of class %d:\n",i+1);
                    for(j=0;j<n;j++)
                    {
                              scanf("%d",&p[i*n+j]);
                    }
          }
}
double Average(int *p,int m,int n)
{
          int i,j,sum=0;
          for(i=0;i<m;i++)
          {
                    for(j=0;j<n;j++)
                    {
                              sum+=p[i*n+j];
                    }
          }
          return (double)sum/(n*m);
}
