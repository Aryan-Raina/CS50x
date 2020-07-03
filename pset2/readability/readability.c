#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>


int main(void)
{
    int alpha = 0, words = 1, sentences = 0;
    string text = get_string("Text: ");//prompt user for input
    
    for (int i = 0; text[i] != '\0'; i++)//loop through every character of string
    {
        if (isalpha(text[i]))//count alphabets
        {
            alpha++;
        }
        if (text[i] == ' ')
        {
            words++;
            while (text[i + 1] == ' ')
            {
                i++;
            }
        }
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')//add it as a sent if there is a punctuation
        {
            sentences++;
        }
    }
    double L = 100 * (double)alpha / (double)words;//average letters per 100 words
    double S = 100 * (double)sentences / (double)words;//average sentences per 100 words
    
    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    
}