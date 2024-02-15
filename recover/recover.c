#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    //Acccept command line
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    //open memeory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];

    //while there are still signs to read
  int fileNo = 0;
  bool isFileOpened = false;
  FILE *fileJPG;
    while(fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            string fileName = malloc(8, sizeof(int));
            sprintf(fileName, "%03d.jpg", fileNo);
            if(isFileOpened) //previous file is still open - close it and open new one
            {
                fclose(fileJPG);
                fileJPG = fopen(fileName, "w");
                fileNo++;
            }
            else // no file is opened - first finding
            {
                fileJPG = fopen(fileName, "w");
                fileNo++;
            }
            //printf("-----------------------------------------------New file. S = %i\n",s);

            for (int i = 0; i < 512; i++) // print buffer
            {
                printf("%02x ", buffer[i]);
                if ((i + 1) % 16 == 0) {
                    printf("\n");
                }
            }

        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        }
    }


    //create a new file .jpeg

    fclose(card);
}
