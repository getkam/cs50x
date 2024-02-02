#include <cs50.h>
#include <stdio.h>

bool verifyCheckSum(long int number);
string getCardProvider(long int number);

int main(void)
{
    long int number;

    do
    {
        number = get_long("Number: ");
    }
    while(number < 0);


    if (verifyCheckSum(number))
    {
        printf("%s", getCardProvider(number));
    }
    else
    {
        printf("INVALID\n");
    }

}

bool verifyCheckSum(long int number)
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
    return (sumOfMultiplied % 10)? true : false;
}

string getCardProvider(long int number)
{
    int legth = 1;
    int firstTwoDigits = 0;

    for(long int remNo = number; remNo > 10;  remNo=remNo/10)
    {
        firstTwoDigits = remNo;
        legth ++;
    }
//American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit
    if((firstTwoDigits == 34 || firstTwoDigits == 37) && legth ==15)
    {
        return "AMEX\n";
    }
    else
    if(firstTwoDigits / 10 == 4 && (legth == 13 || legth == 16))
    {
        return "VISA\n";
    }
    else
    if(firstTwoDigits >= 51 && firstTwoDigits <= 55 && legth == 16)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}
