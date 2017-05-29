//program that gets your name then outputs the initials in uppercase
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)

{
    string s;
    
    s = GetString(); //gets name
    printf("%c", toupper(s[0])); //gets first initial (uppercase)


    for (int i = 0, n = strlen(s)-1; i < n; i++) //gets each other initial (uppercase)
    {
        if ((char)s[i] == ' ')
        {
            printf("%c", toupper(s[i+1]));
        }
    }
    printf("\n");
}