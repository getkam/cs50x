#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Acccept command line
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // open memeory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];

    // while there are still signs to read
    int fileNo = 0;
    bool isFileOpened = false;
    FILE *fileJPG;
    char *fileName;

    int testIndex = 0;
    while (fread(buffer, 1, 512, card) == 512 && fileNo < 4)
    {
        printf("%i\n", testIndex);
        // printf("-----------------------------------------------New file. S = %i\n",s);
        for (int i = 0; i < 4; i++) // print buffer
            {
                printf("%02x ", buffer[i]);
            }
             printf("\n");
        testIndex++;
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fileName = malloc(8);
            sprintf(fileName, "%03d.jpg", fileNo);
            if (isFileOpened) // previous file is still open - close it and open new one
            {
                fclose(fileJPG);
                printf("-------------file closed\n");
                fileJPG = fopen(fileName, "w");
                printf("-------------file opened------%s\n", fileName);
                fileNo++;
            }
            else // no file is opened - first finding
            {
                fileJPG = fopen(fileName, "w");
                printf("-------------file opened------%s\n", fileName);
                isFileOpened = true;
                fileNo++;
            }

            // write to the file
            fwrite(buffer, sizeof(uint8_t), 512, fileJPG);

        }

        if (isFileOpened)
        {
            // write to the file
            fwrite(buffer, sizeof(uint8_t), 512, fileJPG);
        }
    }
    if (isFileOpened)
    {
        fclose(fileJPG);
         printf("-------------file closed\n");

    }

    // create a new file .jpeg
    free(fileName);
    fclose(card);
}
