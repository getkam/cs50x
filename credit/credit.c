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
    long remainedNumber;

    do
    {
       int rest = (int) remainedNumber % 10;
       remainedNumber = remainedNumber / 10;
       printf("rest: %i\n", rest);
       printf("remained number: %l\n", remainedNumber);
    }
    while(remainedNumber > 0);
}

