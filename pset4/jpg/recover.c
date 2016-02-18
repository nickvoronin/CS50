/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

// global variables
BYTE block[BLOCK_SIZE];
int image_counter = 0; 
char image_name[7];

// prototypes
string generate_name();
bool contains_image();
bool end_of_image();

int main(int argc, char* argv[])
{   
    // check command line argument
    if (argc != 1)
    {
        printf("Usage: ./recover\n");
        return 1;
    }
    
    // open file with lost data
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open ""card.raw"".\n");
        return 2;
    }
    
    // Initialise output file
    FILE* output = NULL;   
    // string str = (string)malloc(size * sizeof(char));
    
    while(fread(&block, sizeof(block), 1, card) == 1)
    {
        if (contains_image(block))
        {
            // if opened close image file
            if (output != NULL) 
            {
                fclose(output);
            }
            // generate new filename and store it in image_name
            
            // open new file
            output = fopen(generate_name(), "w");
            if (output == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", image_name);
                return 3;
            }
            
            // write image data to the new file
            fwrite(&block, sizeof(block), 1, output);
        }    
        else if (image_counter > 0)
        {
            fwrite(&block, sizeof(block), 1, output);
        }
    }

    // close files
    fclose(output);
    fclose(card);
    return 0;
}    

// generate name for new jpeg file
string generate_name()
{
    sprintf(image_name, "%03d.jpg", image_counter);
    image_counter++;
    return image_name;
}

// check if current block contains an image
bool contains_image(BYTE b[])
{
    if (b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff && b[3] >= 0xe0)
        return true;
    return false;
}

bool end_of_image(BYTE b[])
{
    if (b[0] == 0x00) return true;
    return false;
}