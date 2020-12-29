#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main(void)
{
    string text;
    text = get_string("Text: ");

    int sum_letters = 0;
    int sum_periods = 0;
    int num_spaces = 0;
    int max = strlen(text);


    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sum_letters += 1;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sum_periods += 1;
        }
        else if (text[i] == ' ')
        {
            num_spaces += 1;
        }
    }


    float av_letter, av_sentence;
    int num_words = num_spaces + 1;

    av_letter = ((float)sum_letters / (float)num_words) * 100;
    av_sentence = ((float)sum_periods / (float)num_words) * 100;

    float index = (0.0588 * av_letter) - (0.296 * av_sentence) - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }

}
