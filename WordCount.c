#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
char *word;
int count;
struct Node *next;
};
typedef struct Node Node;
Node *head = NULL;
void insert(char *word, Node *q, Node *p);
int main()
{
    char word[100];
    Node *p, *q;
    while(scanf("%s", word) != EOF) {
        for (p = head, q = NULL; p != NULL; q = p, p = p->next) {
            int cond = strcmp(word, p->word);
            if (cond == 0) {
                p->count ++;
                break;
            } else if (cond < 1) {
                insert(word, q, p);
                break;
            }
        }
        if (p == NULL) {
            insert(word, q, p);
        }
    }
    for(p = head; p != NULL; p = p->next)
        printf("%s %d\n", p->word, p->count);
    return 0;
}

void insert(char *word, Node *q, Node *p)
{
    Node *r = (Node *)malloc(sizeof(Node));
    r->word = (char *)malloc(strlen(word) + 1);
    strcpy(r->word, word);
    r->count = 1;
    r->next = p;
    if (q != NULL)
        q->next = r;
    else
        head = r;
}
