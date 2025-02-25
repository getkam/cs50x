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
    while (number < 0);

    bool checksum = verifyCheckSum(number);
    string code = getCardProvider(number);

    if (checksum == true)
    {
        printf("%s", code);
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
    for (long int remainingNo = number; remainingNo > 0; remainingNo = remainingNo / 10)
    {
        int digit = remainingNo % 10;

        if (index % 2 > 0)
        {
            sumOfNOTMultiplied = sumOfNOTMultiplied + digit;
        }
        else if (index % 2 == 0)
        {
            mutiplied = digit * 2;
            int sumOfDigits = 0;
            do
            {
                sumOfDigits = sumOfDigits + mutiplied % 10;
                mutiplied = mutiplied / 10;
            }
            while (mutiplied > 0);
            sumOfMultiplied = sumOfMultiplied + sumOfDigits;
        }
        index++;
    }
    int total = sumOfMultiplied + sumOfNOTMultiplied;

    return (total % 10 == 0) ? true : false;
}

string getCardProvider(long int number)
{
    int legth = 1;
    int firstTwoDigits = 0;

    for (long int remainingNo = number; remainingNo > 10; remainingNo = remainingNo / 10)
    {
        firstTwoDigits = remainingNo;
        legth++;
    }
    if ((firstTwoDigits == 34 || firstTwoDigits == 37) && legth == 15)
    {
        return "AMEX\n";
    }
    else if (firstTwoDigits / 10 == 4 && (legth == 13 || legth == 16))
    {
        return "VISA\n";
    }
    else if (firstTwoDigits >= 51 && firstTwoDigits <= 55 && legth == 16)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}
