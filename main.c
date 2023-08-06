#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int minus;

int main()
{
    char c;
    while(scanf("%c",&c) != -1)
    {
        if( islower(c))
        {
            c = toupper((int)c);

        }
        minus = (int)c - (int)'A';
        for (int i =0;i <= minus - 1;i=i+1)
        {
            int cent = (int)'A' + i;


            for(int j = i; j >= -i;j--)
            {

                printf("%c",cent - abs(j));
            }
            printf("\n ");
        }

    }
    return 0;
}



