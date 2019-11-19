#include "tools.h"
#include "score_largestNumber.h"
#include <stdio.h>
#include <iostream>

void print_word_score(int start_x, int start_y)
{
    SetCursorPosition(start_x*2, start_y);
    cout << "Score: ";
}

void print_score(int start_x, int start_y, int score)
{
    SetCursorPosition(start_x*2, start_y);
    cout << score;
}

void print_word_largest_number(int start_x, int start_y)
{
    SetCursorPosition(start_x*2, start_y);
    cout << "Largest number: ";
}

void print_largest_number(int start_x, int start_y, int content[])
{
    int largest_number = largest(content);
    SetCursorPosition(start_x*2, start_y);
    cout << largest_number;
}

int largest(int content[])
{
    int largestNumber = content[0];
    for (int i = 1; i < 16; i++)
    {
        if (content[i] > largestNumber)
            largestNumber = content[i];
    }
    return largestNumber;
}
