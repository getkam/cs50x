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

            for (int n = h - 1, gh = 0; n < h + 2; n++, gh++)
            {
                for (int k = w - 1, gw = 0; k < w + 2; k++, gw++)
                {
                    if ((n >= 0 && (n <= (height - 1))) && (k >= 0 && (k <= (width - 1))))
                    {
                        //printf("I'm in inside loop .......................\n");
                        //printf("index: %i\n", index);
                            gXRed += image[n][k].rgbtRed * gXArr[gh][gw];
                            gXGreen += image[n][k].rgbtGreen * gXArr[gh][gXw];
                            gXRed += image[n][k].rgbtBlue * gXArr[gh][gw];

                            gYRed += image[n][k].rgbtRed * gYArr[gh][gw];
                            gYGreen += image[n][k].rgbtGreen * gYArr[gh][gw];
                            gYBlue += image[n][k].rgbtBlue * gYArr[gh][gw];
                    }
                }
            }

            // if (h > 0 && h < (height - 1) && w > 0 && w < (width - 1)) // check if not border
            // {
            //     for (int gXh = -1; gXh < 2; gXh++)
            //     {
            //         for (int gXw = -1; gXw < 2; gXw++)
            //         {
            //                 gXRed += image[h + gXh][w + gXw].rgbtRed * gXArr[gXh][gXw];
            //                 gXGreen += image[h + gXh][w + gXw].rgbtGreen * gXArr[gXh][gXw];
            //                 gXRed += image[h + gXh][w + gXw].rgbtBlue * gXArr[gXh][gXw];
            //         }
            //     }

            //     for (int gYh = -1; gYh < 2; gYh++)
            //     {
            //         for (int gYw = -1; gYw < 2; gYw++)
            //         {
            //                 gYRed += image[h + gYh][w + gYw].rgbtRed * gYArr[gYh][gYw];
            //                 gYGreen += image[h + gYh][w + gYw].rgbtGreen * gYArr[gYh][gYw];
            //                 gYBlue += image[h + gYh][w + gYw].rgbtBlue * gYArr[gYh][gYw];
            //         }
            //     }

            //     // printf("I'm in inside loop .......................\n");
            //     // printf("index: %i\n", index);
            // }

            double tempRed = gXRed * gXRed + gYRed * gYRed;
            edged[h][w].rgbtRed = tempRed > 255 ? (BYTE)255 : (BYTE)round(tempRed);

            double tempGreen = gXGreen * gXGreen + gYGreen * gYGreen;
            edged[h][w].rgbtGreen = tempGreen > 255 ? (BYTE)255 : (BYTE)round(tempGreen);

            double tempBlue = gXBlue * gXBlue + gYBlue * gYBlue;
            edged[h][w].rgbtBlue = tempBlue > 255 ? (BYTE)255 : (BYTE)round(tempBlue);

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edged[i][j];
        }
    }
    return;
}
