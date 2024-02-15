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
    while (fread(buffer,1,512, card) == 512)
    {
        printf("%s", buffer);
    }
    //create a new file .jpeg

    fclose(card);
}
