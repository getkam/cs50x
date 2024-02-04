#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string s);
int countSentences(string s);
int countWords(string s);
int calculateIndex(int letters, int sentences, int words);
void printGrade(int index);

int main(void)
{
    string text = get_string("Text: ");

    int lettersAmount = countLetters(text);
    int sentencesAmount = countSentences(text);
    int wordsAmount = countWords(text);

    printf("letters: %i\n", lettersAmount);
    printf("sentences: %i\n", sentencesAmount);
    printf("words: %i\n", wordsAmount);
    int index = calculateIndex(lettersAmount, sentencesAmount, wordsAmount);
    printf("index: %i\n", index);
    printGrade(index);
}

int countLetters(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (isalpha(s[i]))
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
        bool isNextBlank = (s[i + 1] == 0 || s[i + 1] == ' ') ? true : false;
        if (c == '.' || ((c == '?' || c == '!') && isNextBlank))
        {
            counter++;
        }
    }
    if (strlen(s) > 0 && counter == 0)
    {
        counter++;
    }
    return counter;
}

int countWords(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (isblank(s[i]))
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
    printf("l: %f\n", l);
    printf("s: %f\n", s);
    printf("index inside: %f\n", 0.0588 * l - 0.296 * s - 15.8);
    return round(0.0588 * l - 0.296 * s - 15.8);
}

void printGrade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
