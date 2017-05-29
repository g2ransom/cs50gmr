/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

#define SIZE 1000

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};

// create a counter for the amount of words in dictionary memory
int count = 0;

// hash function prototype
int hash_function(const char* needs_hashing);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // create temp variable that stores lowercase version of the word
    char temp[LENGTH + 1];
    
    // set variable for length of char in word string
    int len = strlen(word);

    
    // create structure for case insensitivity
    for(int letter = 0; letter < len; letter++)
    {
            // case for the apostrophe
            if(temp[letter] == '\'')
            {
                temp[letter] = word[letter];
            }
            
            else
            {
                // make letter lowercase
                temp[letter] = tolower(word[letter]);
            }
    }
    
    // add null terminator
    temp[len] = '\0';
    
    
    // hash the word to see which bucket it's in
    int bucket = hash_function(temp);
    
    if(hashtable[bucket] == NULL)
    {
        return false;
    }
    
    // create cursor to compare the words
    node* cursor = hashtable[bucket];
    
    // search the word in the hashtable's linked list using strcmp
    while(cursor != NULL)
    {
        if(strcmp(temp, cursor->word) == 0)
        {
            // return true is the word is in the linked list - proven by strcmp function
            return true;
        }
        // if the current cursor was not the same as "word", then move to the next node in linked list
        cursor = cursor->next;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    
    // if the file doesn't exist
    if(dict == NULL)
    {
        puts("Cannot open the dictionary file.");
        return false;
    }
    
    // create index for hashtable function
    int index = 0;
    
    // create an array for word to be put into
    char word[LENGTH+1];
    
    // loop that places each word into hash table and linked list until the end of the file is reached
    while (fscanf(dict, "%s\n", word)!= EOF)
    {
        // create a new node in memory for each word
        node* new_node = malloc(sizeof(node));
        new_node->next = NULL;
        
        // put word in the new node
        strcpy(new_node->word, word);
        
        // increase the word count
        count++;
        
        
        // initialize variable that uses hash_function to find the index of word
        index = hash_function(word);
        
        // case if hashtable index of does not yet have any words
        if(hashtable[index] == NULL)
        {
            hashtable[index] = new_node;
        }
        
        // case if hashtable index already has words
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }
    }
    
    // close the file
    fclose(dict);
    
    return true;
}

/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_function(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % SIZE;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return count from the load function
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    // free each node in each hashtable
    for(int i = 0; i < SIZE; i++)
    {
        node* cursor;
        cursor = hashtable[i];
        
        // form a temporary node to individually free each node
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next,
            free(temp);
        }
    }
    return true;
}
