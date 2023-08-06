#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct node
{
    char* word;
    int count;
    struct node* next;
};
typedef struct node node;
int main()
{
    char word[100];
    node*head=NULL;//暂时的，一会就改了
    node*p,*q;
    FILE *fp=fopen("D:\\Cwork\\rantional\\open.txt","r");
     FILE *fp1=fopen("D:\\Cwork\\rantional\\output.txt","w");
    if(fp==NULL) exit(1);
    if(fp1==NULL) exit(1);

    while(fscanf(fp,"%s",word)!=EOF)
    {

        for(p=head,q=NULL;p!=NULL;q=p,p=p->next)//p!=NULL
        {
            int cond=strcmp(word,p->word);
            if(cond==0) //相同
            {
                p->count++;
                break;
            }
            else if(cond<0)//新建一个节点
            {
                node *r=(node*)malloc(sizeof(node));//新分一块空间
                r->word=(char*)malloc(strlen(word)+1);//存新字符的空间
                strcpy(r->word,word);//存新字符到结构体的word中
                r->count=1;
                r->next=p;//下面插节点
                if(q!=NULL)//不是第一个节点
                  q->next=r;
                else//是第一个节点，换头
                {
                    head=r;
                    break;//不需要判断后面的是否同了
                }


            }
        }

        if(p==NULL)
        {
            node *r=(node*)malloc(sizeof(node));//新分一块空间
                r->word=(char*)malloc(strlen(word)+1);//存新字符的空间
                strcpy(r->word,word);//存新字符到结构体的word中
                r->count=1;
                r->next=p;//下面插节点
                if(q!=NULL)//不是第一个节点
                  q->next=r;
                else//是第一个节点，换头
                   head=r;


        }


    }
    for(p=head;p!=NULL;p=p->next)
        fprintf(fp1,"%s %d",p->word,p->count);
        fclose(fp);
        fclose(fp1);
    return 0;
}
