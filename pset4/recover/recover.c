#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover image");
        return 1;
    }
    
    // Assigning variables and opening the memory card file
    FILE *raw = fopen(argv[1], "r");
    unsigned char buffer[512];
    int img_no = 0;
    char name[8];
    FILE *img = NULL;
    
    if (raw == NULL)
    {
        printf("File doesn't exist");
        return 2;
    }
    
    // Loops through every 512B in memory card
    while (fread(buffer, sizeof(buffer), 1, raw) == 1)
    {
        // If a JPEG start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Closes previous file if not first JPEG
            if (img_no > 0)
            {
                fclose(img);
            }
            
            // For making new JPEGs
            sprintf(name, "%03i.jpg", img_no);
            img = fopen(name, "w");
            fwrite(buffer, sizeof(buffer), 1, img);
            img_no++;
        }
        else if (img_no > 0)
        {
            // Writes in the last JPEG
            fwrite(buffer, sizeof(buffer), 1, img);
        }
        
    }
    // Closes memory card
    fclose(raw);
}