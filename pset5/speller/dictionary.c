// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of words in the dict
unsigned int total_words = 0;

// Number of buckets in hash table
const unsigned int N = 93000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Getting to the linked list which can contain word in #table
    int h = hash(word);
    node *cursor = table[h];
    
    // Run till cursor reaches the end
    while (cursor != NULL)
    {
        // If strings are same return true(case insensitive)
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        
        // Update Cursor
        cursor = cursor->next;
    }
    
    return false;
}

// djb2 algorithm for hashing
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long h = 5381;
    int c = *word;
    c = tolower(c);
    
    while (*word)
    {
        h = ((h << 5) + h) + c;
        c = *word++;
        c = tolower(c);
    }
    return h % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opening the dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // Decclaring a string
    char w[LENGTH + 1];
    
    // Main while loop that loops through the dict
    while (fscanf(dict, "%s", w) != EOF)
    {
        // Declaring pointer n to a node that helps add word to #table
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        // Adding word to #table
        strcpy(n->word, w);
        n->next = table[hash(w)];
        table[hash(w)] = n;
        
        // Counts total words in dict
        total_words++;
        
        // Resetting n 
        n = NULL;
    }
    
    // Closing dictionary
    fclose(dict);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            tmp = NULL;
            
            if (tmp != NULL)
            {
                return false;
            }
        }
    }

    return true;
}
