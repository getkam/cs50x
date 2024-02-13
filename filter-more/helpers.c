#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int tmp = round(avg);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = (BYTE)round(tmp);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfHeight = height / 2;
    for (int i = 0; i < halfHeight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    double red;
    double green;
    double blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            if ((i > 0) && (i < (height - 1)) && (j > 0) && (j < (width - 1)))
            {
                //printf("I'm in.................................\n");
                //printf("n = i-1: %i\n", i - 1);
                //printf("k = j-1: %i\n", j - 1);
                int index = 0;
                for (int n = i - 1; n < i + 2; n++)
                {
                    if (i > 0 && (i < (height - 1)))
                    {
                        for (int k = j - 1; k < j + 2; k++)
                        {
                            if (j > 0 && (j == (width - 1)))
                            {
                                //printf("I'm in inside loop .......................\n");
                                //printf("index: %i\n", index);
                                red += image[n][k].rgbtRed;
                                green += image[n][k].rgbtGreen;
                                blue += image[n][k].rgbtBlue;
                                index++;
                            }
                        }
                    }
                }
                //printf("index: %i\n", index);

                //printf("sum red: %f, rounded avg: %f\n", red, round(red / 9.0));
                //printf("sum green: %f, rounded avg: %f\n", green, round(green / 9.0));
                //printf("sum blue: %f, rounded avg: %f\n", blue, round(blue / 9.0));

                image[i][j].rgbtRed = (BYTE)round(red / index);
                image[i][j].rgbtGreen = (BYTE)round(green / index);
                image[i][j].rgbtBlue = (BYTE)round(blue / index);
            }

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
