//Find the minimum amount of coins needed for a given amount change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    float change;
    int total;
    int count = 0;
    do
    {
        //getting input from the user
        printf("How much change?\n");
        change = GetFloat();
        total = round(change*100); //converting to cents
    } 
    while(change <= 0);
    
    //find the minimum amount of coin for change 
    while(total >= 25) //number of quarters
    {
    count++;
    total -= 25;
    }
    
    while(total >= 10) //dimes
    {
        count++;
        total -= 10;
    }
    
    while(total >= 5) //nickels
    {
        count++;
        total -= 5;
    }
    
    while(total >= 1) //pennies
    {
        count++;
        total -= 1;
    }
    
    printf("%d\n", count); //output statement
    
}
    
    
    
