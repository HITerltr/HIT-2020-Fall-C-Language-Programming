#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/*刘天瑞*/
void GuessNumber(int number);
int MakeNumber();
int main(void)
{
int seed, number, times,i = 0;

    scanf("%d %d",&seed,&times);
    srand(seed);
do{
           number = MakeNumber();
           GuessNumber(number);
           i++;
    }while(i < times);
    return 0;
}
int MakeNumber()
{

    return rand() %100+1;
}
void GuessNumber(int number)
{
    int guess,counter = 0;
    int ret;
    do
{
    ret = scanf("%d",&guess);
           while(ret != 1)
           {
               while(getchar() != '\n');
               ret = scanf("%d",&guess);
           }
           counter++;
           if(guess > number)
               printf("Bigger than the answer,guess again:\n");
           else if(guess < number)
               printf("Smaller than the answer,guess again:\n");
           else
               printf("Correct!\n");
     }while(guess != number && counter < 7);
     printf(" Wrong!\n ");
     return 0;
}
