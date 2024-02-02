#include <cs50.h>
#include <stdio.h>

int verifyCheckSum(long int number);

int main(void)
{
    long int number;

    do
    {
        number = get_long("Number: ");
    }
    while(number < 0);

    int isCorrect = verifyCheckSum(number);
    printf("1 if is correct?: %i\n", isCorrect);
}

int verifyCheckSum(long int number)
{
    int mutiplied = 0;
    int sumOfMultiplied = 0;
    int sumOfNOTMultiplied = 0;

    int index = 1;
    for(long int remNo = number; remNo > 0;  remNo=remNo/10)
    {
        int rest = remNo % 10;

        if (index % 2 > 0) //not multiplied
        {
            sumOfNOTMultiplied = sumOfNOTMultiplied + rest;
        }
        else
        if(index % 2 == 0)//multiplied
        {
            mutiplied = rest*2;
            int sumOfDigits = 0;
            do
            {
                sumOfDigits = sumOfDigits + mutiplied % 10;
                mutiplied = mutiplied / 10;
            }
            while(mutiplied > 0);

            sumOfMultiplied = sumOfMultiplied + sumOfDigits;
        }
        index++;
    }

    printf("%i\n", sumOfMultiplied);
    return (sumOfMultiplied % 10)? 1 : 0;
}
