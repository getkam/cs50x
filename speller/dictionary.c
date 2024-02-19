// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

typedef struct trieNode
{
    struct trieNode *children[N];
    bool isEnd;
} trieNode;

// Represents a node in a hash table
typedef struct hashNode
{
    char firstLetter;
    struct trieNode *next;
} hashNode;

// Hash table
trieNode *table[N];

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
    //Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if ( source == NULL )
    {
        printf("Error during opening dictionary");
        return 1;
    }

    // Read each word in the file
    char word[45];
    while (fscanf(source, "%s", word) != EOF)
    {
        // Add each word to the hash table
        insert(word);
    }


    //close the dictionary
    fclose(dictionary);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

void insert(char *word)
{
    int index = hash(word);
   if(table[index] == NULL)
   {
    table[index] = malloc
   }
}

trieNode *createNewNode()
{

}
