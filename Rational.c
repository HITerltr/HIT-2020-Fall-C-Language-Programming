#include <stdio.h>
#include <stdlib.h>
struct rational {
int numerator;
int denominator;
};
typedef struct rational rational;
void output(rational x);
void input(rational *p);
rational add(rational x, rational y);
int euclid(int a, int b);
int compare(rational x, rational y);
void swap(rational d[], int i, int j);
void sort(rational d[], int n);

int main()
{
/*
    rational x;
    rational *p = &x;
*/
/*
    (*p).numerator = 1;
    (*p).denominator = 4;
*/
/*
    p->numerator = 1;
    p->denominator = 4;
*/

//    input(&x);



//    output(x);

    rational d[5];// = {{2,3},{3,5},{4,7},{5,6},{7,8}};
    int i;
    for (i = 0; i < 5; i ++)
        input(&d[i]);
    sort(d, 5);
    for (i = 0; i < 5; i ++){
        output(d[i]);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}

void swap(rational d[], int i, int j)
{
    rational temp;
    temp = d[i];
    d[i] = d[j];
    d[j] = temp;
}
void sort(rational d[], int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i ++){
        int min_index = i;
        for (j = i + 1; j < n; j ++)
            if (compare(d[j], d[min_index]) < 0)
                min_index = j;
        swap(d, i, min_index);
    }
}
void output(rational p)
{
    printf("%d/%d", p.numerator, p.denominator);
}
void input(rational *p)
{
    scanf("%d/%d", &(p->numerator), &(p->denominator));
}

rational add(rational x, rational y)
{
    rational z;
    z.denominator = x.denominator * y.denominator;
    z.numerator = x.numerator * y.denominator + y.numerator * x.denominator;

    int g = euclid(z.numerator, z.denominator);
    z.numerator /= g;
    z.denominator  /= g;
    return z;
}

int euclid(int a, int b)
{
    /*
    if (b == 0)
        return a;
    else
        return euclid(b, a%b);
        */
    int r;
    while (b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int compare(rational x, rational y)
{
    if (x.denominator < 0) {
        x.denominator *= -1;
        x.numerator *= -1;
    }
    if (y.denominator <0) {
        y.denominator *= -1;
        y.numerator *= -1;
    }
    return x.numerator * y.denominator - y.numerator * x.denominator;
}
