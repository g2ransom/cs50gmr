/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n < 0)
    {
        return false;
    }
    
    else
    {
        int max = n - 1;
        int min = 0;
        
        while(n > 0)
        {
            int midpoint = (max+min) / 2;
            
            if(value[midpoint] == value)
            {
                return true;
            }
            
            else if(value[midpoint] > value)
            {
                max = midpoint - 1;
            }
            
            else if(value[midpoint] < value)
            {
                min = midpoint + 1;
            }
        }
        
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp;
    for(int i = 0; i < (n - 1); i++)
    {
        int min = i;
        
        for(int j = i + 1; j < n; j++)
        {
            if(values[j] < values[min])
            {
                min = j;
            }
            
        temp = values[min]; //assigning temp value       
        values[i] = values[min]; //assigning value in i array to minimum value
        values[i] = temp; //assigning back to the temp value before looping back into loop
                
            }
            
            
        }
    }

}