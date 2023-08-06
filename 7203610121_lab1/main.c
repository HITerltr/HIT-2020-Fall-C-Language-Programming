#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10
#define STU_NUM 30
#define COURSE_NUM 6
typedef struct student_t_distribution
{
          long num;
          char name[MAX_LEN];
          float score[COURSE_NUM];
          float sum;
          float aver;
}STU;
int Menu(void);
void ReadScore(STU stu[],int n,int m);
void AverSumofEveryStudent(STU stu[],int n,int m);
void AverSumofEveryCourse(STU stu[],int n,int m);
void SortbyScore(STU stu[],int n,int m,int (* compare)(float a,float b));
int Ascending(float a,float b);
int Descending(float a,float b);
void SwapFloat(float *x,float *y);
void SwapLong(long *x,long *y);
void SwapChar(char x[],char y[]);
void AsSortbyNum(STU stu[],int n,int m);
void SortbyName(STU stu[],int n,int m);
void SearchbyNum(STU stu[],int n,int m);
void SearchbyName(STU stu[],int n,int m);
void StatisticAnalysis(STU stu[],int n,int m);
void PrintScore(STU stu[],int n,int m);
void WritetoFile(STU record[],int n,int m);
void ReadfromFile(STU record[],int *n,int *m);
int main()
{
     char ch;
     int n=0,m=0;
     STU stu[STU_NUM];
     printf("Input student number(n<%d):",STU_NUM);
     scanf("%d",&n);
     printf("Input course number(m<=%d):",COURSE_NUM);
     scanf("%d",&m);
     while(1)
     {
               ch=Menu();
               switch(ch)
               {
                         case 1:ReadScore(stu,n,m);
                         break;
                         case 2: AverSumofEveryStudent(stu,n,m);
                         break;
                         case 3:AverSumofEveryCourse(stu,n,m);
                         break;
                         case 4:SortbyScore(stu,n,m,Descending);
                         printf("\nSort in descending order by score:\n");
                         PrintScore(stu,n,m);
                         break;
                         case 5:SortbyScore(stu,n,m,Ascending);
                         printf("\nSort in ascending order by score:\n");
                         PrintScore(stu,n,m);
                         break;
                         case 6:AsSortbyNum(stu,n,m);
                         printf("\nSort in ascending order by number:\n");
                         PrintScore(stu,n,m);
                         break;
                         case 7:SortbyName(stu,n,m);
                         printf("\nSort in dictionary order by name:\n");
                         PrintScore(stu,n,m);
                         break;
                         case 8:SearchbyNum(stu,n,m);
                         break;
                         case 9:SearchbyName(stu,n,m);
                         break;
                         case 10:StatisticAnalysis(stu,n,m);
                         break;
                         case 11:PrintScore(stu,n,m);
                         break;
                         case 12:WritetoFile(stu,n,m);
                         break;
                         case 13:ReadfromFile(stu,n,m);
                         break;
                         case 0:printf("End of program!");
                          exit(0);
                          default:printf("Input error!");
               }
     }

    return 0;
}
int Menu(void)
{
          int itemSelected;
          printf("Management for students'scores\n ");
          printf("1.Input record\n");
          printf("2.Calculate total and average score of every course\n");
          printf("3.Calculate total and average score of every student\n");
          printf("4.Sort in descending order by score\n");
          printf("5.Sort in ascending order by score\n");
          printf("6.Sort in ascending order by number\n");
          printf("7.Sort in dictionary order by name\n");
          printf("8.Search by number\n");
          printf("9.Search by name\n");
          printf("10.Statistic analysis\n");
          printf("11.List record\n");
          printf("12.Write to a file\n");
          printf("13.Read from a file\n");
          printf("0.Exit\n");
          printf("Please Input your choice:");
          scanf("%d",&itemSelected);
          return itemSelected;
}
void ReadScore(STU stu[],int n,int m)
{
          int i,j;
          printf("Input student's ID,name and score:\n");
          for(i=0;i<n;i++)
          {
                    scanf("%ld%s",&stu[i].num,stu[i].name);
                    for(j=0;j<m;j++)
                    {
                              scanf("%f",&stu[i].score[j]);
                    }
          }
}
void AverSumofEveryStudent(STU stu[],int n,int m)
{
          int i,j;
          for(i=0;i<n;i++)
          {
                    stu[i].sum=0;
                    for(j=0;j<m;j++)
                    {
                              stu[i].sum+=stu[i].score[j];
                    }
                    stu[i].aver=m>0?stu[i].sum/m:-1;
                    printf("student %d: sum=%.0f,aver=&.0f\n",
                           i+1,stu[i].sum,stu[i].aver);

          }
}
void AverSumofEveryCourse(STU stu[],int n,int m)
{
          int i,j;
          float sum[COURSE_NUM],aver[COURSE_NUM];
          for(j=0;j<m;j++)
          {
                    sum[j]=0;
                    for(i=0;i<n;i++)
                    {
                              sum[i]+=stu[i].score[j];
                    }
                    aver[j]=n>0?sum[j]/n:-1;
                    printf("course %d:sum=%.0f,aver=%.0f\n",j+1,sum[j],aver[j]);
          }
}
void SortbyScore(STU stu[],int n,int m,int (* compare)(float a,float b))
{
          int i,j,k,t;
          for(i=0;i<n-1;i++)
          {
                    k=i;
                    for(j=i+1;j<n;j++)
                    {
                              if((* compare)(stu[j].sum,stu[k].sum)) k=j;
                    }
                    if(k!=i)
                    {
                              for(t=0;t<m;t++)
                              {
                                        SwapFloat(&stu[k].score[t],&stu[i].score[t]);
                              }
                              SwapFloat(&stu[k].sum,&stu[i].sum);
                              SwapFloat(&stu[k].aver,&stu[i].aver);
                              SwapFloat(&stu[k].num,&stu[i].num);
                              SwapFloat(&stu[k].name,&stu[i].name);
                    }
          }
}
int Ascending(float a,float b)
{
          return a<b;
}
int Descending(float a,float b)
{
          return a>b;
}
void SwapFloat(float *x,float *y)
{
          float temp;
          temp=*x;
          *x=*y;
          *y=temp;
}
void SwapLong(long *x,long *y)
{
          long temp;
          temp=*x;
          *x =*y;
          *y=temp;
}

void SwapChar(char x[],char y[])
{
          char temp[MAX_LEN];
          strcpy(temp,x);
          strcpy(x,y);
          strcpy(y,temp);
}
void AsSortbyNum(STU stu[],int n,int m)
{
          int i,j,k,t;
          for(i=0;i<n-1;i++)
          {
                    k=i;

          }
}
