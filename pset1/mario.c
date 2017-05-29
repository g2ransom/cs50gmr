/*A program creates a half pyramid out of (#)s.*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{

int height; 
int i; 
int space;
int hash;

//prompt the user for the half pyramid's height

    do
    {
        printf("height: ");
        height = GetInt();
    }
    while((height < 0) || (height > 23));
    
    
//create the amount of rows for the half pyramid
    for(i = 0; i <= height - 1; i++)
    {    
//create the amount of spaces for the half pyramid
        
        for(space = i + 2; space <= height; space++)
        {
            printf(" ");
        }
            
//create the amount of hashes for the half pyramid
                
        for(hash = i + height; hash + 1 >= height; hash--)
        {
            printf("#");
        }
            
            printf("\n");
    }
}