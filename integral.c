#include <stdio.h>
#include <stdlib.h>
#define N 1000000000
double integral(double (*f)(double), double a, double b);
double f1(double x);
double f2(double x);
int main()
{
    double x;
    for (x = 1.0; x <= 4.0; x += 0.01){
        printf("%.2f %f %f\n", x, integral(f1, 1, x), log(x));
//        printf("%.2f %f %f\n", x, integral(f2, 1, x), 1.0 / 3.0 * (x * x * x - 1.0));
    }

    return 0;
}

double integral(double (*f)(double), double a, double b)
{
    double delta = (b - a) / N;
    double x = a;
    double sum = 0;
    int i;
    for (i = 0; i < N; i ++){
        sum += (*f)(x);
        x += delta;
    }
    return sum * delta;
}

double f1(double x)
{
    return 1.0/x;
}

double f2(double x)
{
    return x * x;
}
