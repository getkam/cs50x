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

    int fileNo = 0;
    bool isFileOpened = false;
    FILE *fileJPG;
    char *fileName = malloc(8);

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (isFileOpened)
            {
                fclose(fileJPG);
            }
            sprintf(fileName, "%03d.jpg", fileNo);
            fileJPG = fopen(fileName, "wb");
            isFileOpened = true;
            fileNo++;
        }

        if (isFileOpened)
        {
            fwrite(buffer, sizeof(uint8_t), 512, fileJPG);
        }
    }
    if (isFileOpened)
    {
        fclose(fileJPG);
    }

    free(fileName);
    fclose(card);
}
