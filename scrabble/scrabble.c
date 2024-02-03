#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string s);

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int main(void)
{
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int calculate_score(string s)
{
    int score = 0;

    for (int i = 0, l = strlen(s); i < l ; i++)
    {
        if(s[i])
        {
            if(isupper(s[i]))
            {
                score += POINTS[s[i]-'A'];
            }
            else if (islower(s[i]))
            {
                score += POINTS[s[i]-'a'];
            }
        }
    }

    return score;
}
