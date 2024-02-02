#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while(number < 0);

    int mutiplied;
    int sumOfMultiplied;


    for(long int remainedNumber = number; remainedNumber > 0;  remainedNumber/10)
    {
       int rest = remainedNumber % 10;


       printf("rest: %i\n", rest);
       printf("remained number: %li\n", remainedNumber);
    }
}

