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
    node*head=NULL;//��ʱ�ģ�һ��͸���
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
            if(cond==0) //��ͬ
            {
                p->count++;
                break;
            }
            else if(cond<0)//�½�һ���ڵ�
            {
                node *r=(node*)malloc(sizeof(node));//�·�һ��ռ�
                r->word=(char*)malloc(strlen(word)+1);//�����ַ��Ŀռ�
                strcpy(r->word,word);//�����ַ����ṹ���word��
                r->count=1;
                r->next=p;//�����ڵ�
                if(q!=NULL)//���ǵ�һ���ڵ�
                  q->next=r;
                else//�ǵ�һ���ڵ㣬��ͷ
                {
                    head=r;
                    break;//����Ҫ�жϺ�����Ƿ�ͬ��
                }


            }
        }

        if(p==NULL)
        {
            node *r=(node*)malloc(sizeof(node));//�·�һ��ռ�
                r->word=(char*)malloc(strlen(word)+1);//�����ַ��Ŀռ�
                strcpy(r->word,word);//�����ַ����ṹ���word��
                r->count=1;
                r->next=p;//�����ڵ�
                if(q!=NULL)//���ǵ�һ���ڵ�
                  q->next=r;
                else//�ǵ�һ���ڵ㣬��ͷ
                   head=r;


        }


    }
    for(p=head;p!=NULL;p=p->next)
        fprintf(fp1,"%s %d",p->word,p->count);
        fclose(fp);
        fclose(fp1);
    return 0;
}
