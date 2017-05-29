/*a program that prompts the user for the length of his or her shower in minutes (as a positive integer) 
and then prints the equivalent number of bottles of water (as an integer) per the sample output below,
wherein underlined text represents some user’s input.*/

#include <stdio.h>
#include <cs50.h>

int main(void)

{
    
    //ask user for length of shower
    printf("minutes: ");
    int length = GetInt();
    
    //convert the length of shower into bottles
    int bottles = length*12;
    
    //print the equivalent number of bottles of water 
    printf("bottles: %d\n", bottles);
}