// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

unsigned int dikiSize = 0;
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

typedef struct trienode
{
    struct trienode *children[N];
    bool end;
} trienode;


// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
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
    dikiSize = 0;

    //Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Error during opening dictionary!");
    }

    char word[45];
    while (fscanf(source, "%s", word) != EOF)
    {
         unsigned int index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = malloc(sizeof(node));
            strcpy(table[index]->word, word);
            table[index]->next = NULL;
            dikiSize++;
        }
        else
        {
            node *temp = table[index]->next;

            node *new = malloc(sizeof(node));
            new->word = &word;
            new->next = temp;
            table[index]->next = new;
            dikiSize++;
        }
    }

    //close the dictionary
    fclose(source);
    return false;
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
        node *ptrNext = table[i]->next;
        node *temp;
        while (ptrNext != NULL)
        {
            temp = ptrNext->next;
            free(ptrNext);
            ptrNext = temp;
        }
    }
    return false;
}
