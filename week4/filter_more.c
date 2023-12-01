#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = new_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp[height][width/2];
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = temp[i][j].rgbtBlue;

            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = temp[i][j].rgbtGreen;

            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float count = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }
                    if (j + m < 0 || j + m > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i+k][j+m].rgbtBlue;
                    sumGreen += image[i+k][j+m].rgbtGreen;
                    sumRed += image[i+k][j+m].rgbtRed;
                    count++;
                }
            }

            temp[i][j].rgbtBlue = round(sumBlue/count);
            temp[i][j].rgbtGreen = round(sumGreen/count);
            temp[i][j].rgbtRed = round(sumRed/count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            float gxBlue = 0;
            float gyBlue = 0;
            float gxGreen = 0;
            float gyGreen = 0;
            float gxRed = 0;
            float gyRed = 0;
            float calBlue = 0;
            float calGreen = 0;
            float calRed = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    if ((i + k) < 0 || (i + k) > height - 1 || (j + m) < 0 || (j + m) > width - 1)
                    {
                        continue;
                    }
                    else
                    {
                        if (m == - 1)
                        {
                            if ((k == -1) || (k == 1))
                            {
                                gxBlue += -image[i+k][j+m].rgbtBlue;
                                gxGreen += -image[i+k][j+m].rgbtGreen;
                                gxRed += -image[i+k][j+m].rgbtRed;
                            }
                            else
                            {
                                gxBlue += -2*(image[i+k][j+m].rgbtBlue);
                                gxGreen += -2*(image[i+k][j+m].rgbtGreen);
                                gxRed += -2*(image[i+k][j+m].rgbtRed);
                            }
                        }
                        else if (m == 1)
                        {
                            if ((k == -1) || (k == 1))
                            {
                                gxBlue += image[i+k][j+m].rgbtBlue;
                                gxGreen += image[i+k][j+m].rgbtGreen;
                                gxRed += image[i+k][j+m].rgbtRed;
                            }
                            else
                            {
                                gxBlue += 2*(image[i+k][j+m].rgbtBlue);
                                gxGreen += 2*(image[i+k][j+m].rgbtGreen);
                                gxRed += 2*(image[i+k][j+m].rgbtRed);
                            }
                        }

                        if (k == 1)
                        {
                            if ((m == -1) || (m == 1))
                            {
                                gyBlue += image[i+k][j+m].rgbtBlue;
                                gyGreen += image[i+k][j+m].rgbtGreen;
                                gyRed += image[i+k][j+m].rgbtRed;
                            }
                            else
                            {
                                gyBlue += 2*(image[i+k][j+m].rgbtBlue);
                                gyGreen += 2*(image[i+k][j+m].rgbtGreen);
                                gyRed += 2*(image[i+k][j+m].rgbtRed);
                            }
                        }
                        else if (k == -1)
                        {
                            if ((m == -1) || (m == 1))
                            {
                                gyBlue += -image[i+k][j+m].rgbtBlue;
                                gyGreen += -image[i+k][j+m].rgbtGreen;
                                gyRed += -image[i+k][j+m].rgbtRed;
                            }
                            else
                            {
                                gyBlue += -2*(image[i+k][j+m].rgbtBlue);
                                gyGreen += -2*(image[i+k][j+m].rgbtGreen);
                                gyRed += -2*(image[i+k][j+m].rgbtRed);
                            }
                        }

                    }

                }
            }
            calBlue = round(sqrt(gxBlue*gxBlue + gyBlue*gyBlue));
            calGreen = round(sqrt(gxGreen*gxGreen + gyGreen*gyGreen));
            calRed = round(sqrt(gxRed*gxRed + gyRed*gyRed));

            temp[i][j].rgbtBlue = (calBlue > 255) ? 255: calBlue;
            temp[i][j].rgbtGreen = (calGreen > 255) ? 255: calGreen;
            temp[i][j].rgbtRed = (calRed > 255) ? 255: calRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
