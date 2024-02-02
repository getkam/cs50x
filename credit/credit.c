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

    int index = 1;
    for(long int remNo = number; remNo > 0;  remNo=remNo/10)
    {
        int rest = remNo % 10;

        if (index%2>0) //not multiplied
        {

        }
        else
        if(index%2==0)//multiplied
        {
            mutiplied = rest*2;
            sumOfDigits = 0;
            do
            {

            }while

            sumOfMultiplied = sumOfMultiplied +
        }
        index++;
        printf("rest: %i\n", rest);
        printf("remained number: %li\n", remNo);
    }
}

