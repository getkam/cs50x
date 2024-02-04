#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool verifyKey(string key);

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("%s key\n", argv[0]);
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        string key = argv[1];
        printf("KEY: %s\n", key);
        printf("ciphertext: ");
        char cph;


        for (int i = 0, l = strlen(plaintext); i < l; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    printf("%c", toupper(key[plaintext[i]-'A']));
                }
                else
                {
                    printf("%c", tolower(key[plaintext[i]-'a']));
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}

bool verifyKey(string key)
{

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else
    {
        for (int i = 0, l = strlen(key); i < l; i++)
        {
            if (!isalpha(key[i]))
            {
                return 1;
            }
        }
}
