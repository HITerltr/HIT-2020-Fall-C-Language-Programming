#include <stdio.h>
#include <stdlib.h>
/*刘天瑞*/

int n1,n2;
char word1[100],word2[100];
int mystrcmp(char a[],char b[],int n,int m);
int main()
{
    int ret;
    scanf("%d",&n1);
    getchar();
    for(int i1=0;i1<n1;i1++) scanf("%c",&word1[i1]);
    scanf("%d",&n2);
    getchar();
    for(int i2=0;i2<n2;i2++) scanf("%c",&word2[i2]);
    ret = mystrcmp(word1,word2,n1,n2);
    if(ret==0) printf("str1 = str2");
    if(ret==1)  printf("str1 < str2");
    if(ret==2)  printf("str1 > str2");
}
int mystrcmp(char a[],char b[],int n,int m)
{
    int t,count=0;
    if(n<m)
    t=n;
    else
    t=m;
    if(n==m)
    {
        for(int p=0;p<t;p++) if(a[p] != b[p])
            count++;
        if(count==0)
            return 0;
    }
    for(int i=0;i<t;i++)
    {
        if(a[i] != b[i])
        {
            if(a[i]<b[i])
                return 1;
            if(a[i]>b[i])
                return 2;
            goto END;
        }
    }
    END:n++;
}
