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
    for(int s = 0; s<16 ; s++)
    {
       fread(buffer, 1, 512, card);

        if (buffer[0] == 0xff && buffer[1]==0xd8)
        {
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
