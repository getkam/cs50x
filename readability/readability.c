#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string s);
int countSentences(string s);
int countWords(string s);
int calculateIndex(int letters, int sentences, int words);

int main(void)
{
    string text  = get_string("Text: ");

    int lettersAmount = countLetters(text);
    int sentencesAmount = countSentences(text);
    int wordsAmount = countWords(text);

    //printf("letters: %i\n", lettersAmount);
    //printf("sentences: %i\n", sentencesAmount);
    //printf("words: %i\n", wordsAmount);
    int index = calculateIndex(lettersAmount, sentencesAmount, wordsAmount);
    printf("index: %i\n", index);
}

int countLetters(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if(isalpha(s[i]))
        {
            counter++;
        }
    }
    return counter;
}

int countSentences(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        char c = s[i];
        if(c == '.' ||  c == '!' || c == '?')
        {
            counter++;
        }
    }
    return counter;
}

int countWords(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        char c = s[i];
        if(s[i] == ' ')
        {
            counter++;
        }
    }
    return ++counter;
}

int calculateIndex(int letters, int sentences, int words)
{
    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;

    return 0.0588 * l - 0.296 * s - 15.8;

}
