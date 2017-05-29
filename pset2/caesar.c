//a program that encrypts messages using Caesar's cipher

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])

{
    if (argc == 1 || argc > 2)
    {
        printf("Error!\n");
    
        return 1;
    }
    
    else
    {
        int k = atoi(argv[1]);
        string p = GetString();
        
        for(int i = 0, n = strlen(p); i < n; i++)
        {
            if(isalpha(p[i])) //if p[i] is in the alphabet
            {
                if (isupper(p[i])) //if p[i] is uppercase
                {
                    int index = p[i] - 'A';
                    int result = (index + k) % 26;
                    int ascii = result + 'A';
                
                    printf("%c", toupper(ascii));
                }
            
                else //if p[i] is lowercase
                {
                    int index = p[i] - 'a';
                    int result = (index + k) % 26;
                    int ascii = result + 'A';
                
                    printf("%c", tolower(ascii));
                }
            }
            
            else if (isdigit(p[i])) //if  p[i] is a digit
            {
                printf("%c", p[i]); //keeps as a digit
            }
            
            else
            {
                printf("%c", p[i]); //keeps as a space
            }
        }
    
        printf("\n"); //gives new line   
        
        return 0;    
    }
        
}
    