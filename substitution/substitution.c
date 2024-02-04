#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>



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
        string key = argv[1];
        printf("KEY: %s\n", key);
        printf("ciphertext: ");
        char cph;


        for (int i = 0, l = strlen(plaintext); i < l; i++)
        {
            int index;
            //index in key
            if (plaintext[i] )
            if (isupper(plaintext[i]))
            {
                index = plaintext[i]-'A';
            }
            else
            {
               index = plaintext[i]-'a';
            }

            printf("%c", key[index]);
        }
        printf("\n");
    }
}
