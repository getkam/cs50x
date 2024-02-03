#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string s);
int countSentences(string s);

int main(void)
{
    string text  = get_string("Text: ");

    int lettersAmount = countLetters(text);
    int sentencesAmount = countSentences(text);

}

int countLetters(string s)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        i++;
    }
    return i;
}

int countSentences(string s)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if(s[i]=='.)
    }
    return i;
}
