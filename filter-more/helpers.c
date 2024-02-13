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
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < (width / 2); w++)
        {

            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width - 1 - w];
            image[h][width - 1 - w] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blured[height][width];
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
            //printf("I'm in.................................\n");
            //printf("n = i-1: %i\n", i - 1);
            //printf("k = j-1: %i\n", j - 1);
            int index = 0;
            for (int n = i - 1; n < i + 2; n++)
            {
                for (int k = j - 1; k < j + 2; k++)
                {
                    if ((n >= 0 && (n <= (height - 1))) && (k >= 0 && (k <= (width - 1))))
                    {
                        //printf("I'm in inside loop .......................\n");
                        //printf("index: %i\n", index);
                        red += image[n][k].rgbtRed;
                        green += image[n][k].rgbtGreen;
                        blue += image[n][k].rgbtBlue;
                        index ++;
                    }
                }
            }
            //printf("index: %i\n", index);

            //printf("sum red: %f, rounded avg: %f\n", red, round(red / index));
            //printf("sum green: %f, rounded avg: %f\n", green, round(green / index));
            //printf("sum blue: %f, rounded avg: %f\n", blue, round(blue / index));

            blured[i][j].rgbtRed = (BYTE)round(red / index);
            blured[i][j].rgbtGreen = (BYTE)round(green / index);
            blured[i][j].rgbtBlue = (BYTE)round(blue / index);
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blured[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gXArr[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gYArr[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int gXRed, gXGreen, gXBlue;
    int gYRed, gYGreen, gYBlue;

    // for ( int i = 0; i < 3; i++)
    // {
    //         for ( int j = 0; j < 3; j++)
    //     {
    //             printf("%i ", Gy[i][j]);
    //     }
    //     printf("\n");
    // }

    RGBTRIPLE edged[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) // for every pixel of the image
        {
            gXRed = gXGreen = gXBlue = 0;
            gYRed = gYGreen = gYBlue = 0; // new pixel
            if (h > 0 && h < (height - 1) && w > 0 && w < (width - 1)) // check if not border
            {
                    for (int gXh = 0; gXh < 3; gXh++)
                    {
                        for (int gXw = 0; gXw < 3; gXw++)
                        {
                            
                        }
                    }

                // printf("I'm in inside loop .......................\n");
                // printf("index: %i\n", index);
                red += image[n][k].rgbtRed;
                green += image[n][k].rgbtGreen;
                blue += image[n][k].rgbtBlue;
                index ++;
            }



        }
    }

    return;
}
