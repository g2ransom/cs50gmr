//a program that encrypts messages using Vigenere's cipher

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{
    if(argc == 1 || argc > 2)
    {
        printf("Error\n");
        
        return 1;
    }
    
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if(isdigit(argv[1][i]))
            {
                printf("Error\n");
                
                return 1;
            }
    }

    {
        string p = GetString();
        string k = argv[1];
        
        
        int j = 0;
        int m = strlen(k);
        
        for(int i = 0, n = strlen(p); i < n; i++) //for each char in "argv[1]"
        {
            if(isalpha(p[i]))
            {
                if(isupper(p[i]))
                {
                    int upper = p[i] - 'A'; //convert p[i] into a int that is zero-indexed/alphabetical
                    int key = toupper(k[j % m]) - 'A';
                    int result = (upper + key) % 26; //convert into a zero-indexed letter
                    int ascii = result + 'A'; //convert that letter back to ascii
                    
                    printf("%c", toupper(ascii));
                }
                    
                else
                {
                    int lower = p[i] - 'a';
                    int key = tolower(k[j % m]) - 'a';
                    int result = (lower + key) % 26;
                    int ascii = result + 'a';
                        
                    printf("%c", tolower(ascii));
                }
                    j++;
            }
            
    
            else if(isdigit(p[i]))
            {
                printf("%c", p[i]);
            }
                    
            else
            {
                printf("%c", p[i]);
            }
        }
            printf("\n");
        
            return 0;
    }
}