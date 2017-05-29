/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    BYTE buffer[512];
    
    // open input file "card.raw"
    FILE* inptr = fopen("card.raw", "r");
    
    // close file if magically "card.raw" is empty
    if(inptr == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }
    
    // output file pointer
    FILE* outptr = NULL;
    
    // declaration of file name and counter for each jpg
    char name[8];
    int counter = 0;
    
    // loop to repeat forming of jpg until the eof
    while(fread(buffer, sizeof(buffer), 1, inptr) == 1)
    {
        // check if the buffer has arrived at the beginning of a jpg
        if((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] >= 0xe0) && (buffer[3] <= 0xef)))
        {
            
            // close an old file, if it is still open
            if(outptr != NULL)
            {
                fclose(outptr);
                outptr = NULL;
            }
            
            // name new file
            sprintf(name, "%03d.jpg", counter);
            counter++;
            
            
            // open output file under new name
            outptr = fopen(name, "w");
            
            // write 512 bytes until new jpg is found
            fwrite(buffer, sizeof(buffer), 1, outptr);
            
            // notification if for some odd reason, the jpg could not be created
            if(outptr == NULL)
            {
                printf("Could not create jpg.\n");
                return 2;
            }
            
            // if we've reached the EOF, then close the file
            if(fread(buffer, sizeof(buffer), 1, outptr) == 1)
            {
                fclose(outptr);
            }
        }
        
        else
        {
            if(outptr != NULL)
            {
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }
    }
    
    // close files after completing program
    fclose(inptr);
    fclose(outptr);
    return 0;
}
