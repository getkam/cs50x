// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

unsigned int dikiSize = 0;
// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

        node *ptr = table[index];
        while (ptr != NULL)
        {
            if(strcasecmp(ptr->word, word) == 0)
            {
                return true;
            }
            ptr = ptr->next;
        }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for( int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    //Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Error during opening dictionary!");
    }

    char dikiWord[LENGTH + 1];
    while (fscanf(source, "%s", dikiWord) != EOF)
    {
        int index = hash(dikiWord);

        node *new = malloc(sizeof(node));
        strcpy(new->word, dikiWord);

        if(table[index] == NULL)
        {
            new->next = NULL;
        }
        else
        {
            new->next = table[index];
        }
        table[index] = new;
        dikiSize++;
    }

    //close the dictionary
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dikiSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i<sizeof(table); i++)
    {
        if(table[i] != NULL){
            node *ptrNext = table[i];

            while (ptrNext->next != NULL)
            {
                node *temp = ptrNext->next;
                free(ptrNext);
                ptrNext = temp;
            }
            free(ptrNext);
        }

    }
    return true;
}
