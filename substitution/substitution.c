#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string getCapitalizedText(string text);

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("%s key\n", argv[0]);
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        string key = getCapitalizedText(argv[1]);
        printf("KEY: %s\n", key);
        printf("ciphertext: ");


        for (int i = 0, l = strlen(plaintext); i < l; i++)
        {
            //index in key


            char cph = plaintext[i] - key[plaintext[i]-'A'];
        }
    }
}

string getCapitalizedText(string text)
{
    char capitalizedTekst[] = "";
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        strncat(capitalizedTekst, toupper(text[i]));
    }
    return capitalizedTekst;
}
