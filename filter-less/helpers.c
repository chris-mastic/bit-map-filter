#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"

int sepiaConversion ( double r, double g, double b, char value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    double avg = 0.0;

    for( int i = 0; i < height -1; i++)
    {
        for (int j = 0; j < width -1; j++)
        {
            //get rgb values
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;

            avg = floor((r+g+b)/3);

            //convert to grayscale by replacing original rgb values w/average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen =avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    for( int i = 0; i < height -1; i++)
    {
        for (int j = 0; j < width -1; j++)
        {
            //get rgb values
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;

            //convert to grayscale by replacing original rgb values w/average
            image[i][j].rgbtRed = sepiaConversion(r,g,b, 'r');
            image[i][j].rgbtGreen = sepiaConversion(r,g,b, 'g');;
            image[i][j].rgbtBlue = sepiaConversion(r,g,b, 'b');;
        }
    }
        return;
}

int sepiaConversion(double r, double g, double b, char value)
{
    int sepiaValue = 0;

    switch (value)
    {
        case 'r':
            sepiaValue = floor(.393 * r + .769 * g + .189 * b);
            break;
        case 'g':
            sepiaValue = floor(.349 * 6 + .686 * g + .168 * b);
               break;
        case 'b':
            sepiaValue = floor(.272 * r + .534 * g + .131 * b);
            break;
    };

    if(sepiaValue > 255)
    {
        sepiaValue = 255;
    }
    if(sepiaValue < 0)
    {
        sepiaValue = 0;
    }


    return sepiaValue;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    double r1 = 0.0;
    double g1 = 0.0;
    double b1 = 0.0;
    double r2 = 0.0;
    double g2 = 0.0;
    double b2 = 0.0;


    for( int i = 0; i < height -1; i++)
    {
        for (int j = width - 1, k = 0; j >= 0; j--, k++)
        {
            //get rgb values of first half
            r1 = image[i][j].rgbtRed;
            g1 = image[i][j].rgbtGreen;
            b1 = image[i][j].rgbtBlue;
            //get rgb values of last half
            r2 = image[i][k].rgbtRed;
            g2 = image[i][k].rgbtGreen;
            b2 = image[i][k].rgbtBlue;


            //reflect the original image
            image[i][k].rgbtRed = r1;
            image[i][k].rgbtGreen = g1;
            image[i][k].rgbtBlue = b1;

            image[i][j].rgbtRed = r2;
            image[i][j].rgbtGreen = g2;
            image[i][j].rgbtBlue = b2;
        }
    }

    return;
}

    // Blur image
    void blur(int height, int width, RGBTRIPLE image[height][width])
    {
        return;
    }
