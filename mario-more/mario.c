#include <cs50.h>
#include <stdio.h>

void printSpaces(int number);

void printHashes(int number);

int main(void)
{
    int height;
    do{
        height = get_int("Height: ");
    }while(height < 0 || height > 9);

    for (int i = 0; i < height; i++)
    {
        int spaces = height - i - 1;
        int hashes = i + 1;

        printSpaces(spaces);
        printHashes(hashes);
        printf("  ");
        printHashes(hashes);
        printSpaces(spaces);
        printf("\n");

  }
}

void printSpaces(int number)
{
  for (int i = 0; i < number; i++)
  {
    printf(" ");
  }
}

void printHashes(int number)
{
  for (int h = 0; h < number; h++)
  {
    printf("#");
  }
}
