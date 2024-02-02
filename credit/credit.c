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

    //checksum
    bool isCorrect = verifyCheckSum(number);
    string x = getCardProvider(number);
    printf("is correct?: %d\n", isCorrect);


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
    int index = 1;
    int firstTwoDigits = 0;
    for(long int remNo = number; remNo > 10;  remNo=remNo/10)
    {
        firstTwoDigits = remNo;
        index ++;
    }
    printf("number of digits:  %i\n", index);
    printf("firstTwoDigits: %i\n", firstTwoDigits);
    return "bla bla";
}
