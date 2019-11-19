#include "tools.h"
#include "score_largestNumber.h"
#include "setup.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>

void setWindow()
{
    int cols = 41;
    int lines = 32;
    system("title 2048");//set the title of the game
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//create a working space
    system(cmd);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //change the color of the title

    SetColor(12);
    draw2(9,7,50);
    SetColor(2);
    draw0(14,7,50);
    SetColor(6);
    draw4(19,7,50);
    SetColor(3);
    draw8(24,7,50);    //draw title 2048

    SetColor(15);
    rule();

    SetColor(14);
    SetCursorPosition(15,25);
    cout << "Are you ready? " ;
    system("pause");

    system("cls");
}

void rule()
{
    SetCursorPosition(11-5,16);
    cout << "Purpose: Get the largest number as you can. \n";
    SetCursorPosition(11+9-5,17);
    cout << "When there is no more space left to get a new number, game over. \n";
    SetCursorPosition(11-5,19);
    cout << "Control: Use arrows to move all the numbers up, down, left, and right. \n";
    SetCursorPosition(11-5,21);
    cout << "Rules: Control the the movements of all the numbers.";
    SetCursorPosition(11+7-5,22);
    cout << "every time when you move, a random new number will appear. \n";
}

void draw2(int start_x, int start_y, int speed)
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            SetCursorPosition(2*(start_x+i),start_y+2*j);
            cout << "2";
            Sleep(speed);
        }
    }

    SetCursorPosition(2*(start_x+2),start_y+1);
    cout << "2";
    Sleep(speed);

    SetCursorPosition(2*start_x,start_y+3);
    cout << "2";
    Sleep(speed);
}

void draw0(int start_x, int start_y, int speed)
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            SetCursorPosition(2*(start_x+2*i),start_y+j);
            cout << "0";
            Sleep(speed);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        SetCursorPosition(2*(start_x+1),start_y+4*i);
        cout << "0";
        Sleep(speed);
    }
}

void draw4(int start_x, int start_y, int speed)
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            SetCursorPosition(2*(start_x+2*i),start_y+j);
            cout << "4";
            Sleep(speed);
        }
    }
    for (int j = 0; j < 2; j++)
    {
        SetCursorPosition(2*(start_x+2),start_y+3+j);
        cout << "4";
        Sleep(speed);
    }
    SetCursorPosition(2*(start_x+1),start_y+2);
    cout << "4";
    Sleep(speed);
}

void draw8(int start_x, int start_y, int speed)
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            SetCursorPosition(2*(start_x+2*i),start_y+j);
            cout << "8";
            Sleep(speed);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        SetCursorPosition(2*(start_x+1),start_y+2*i);
        cout << "8";
        Sleep(speed);
    }
}

void drawFrame()
{
    SetColor(11);
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 23; i++)
        {
            SetCursorPosition(20+i,8+3*j);
            cout << "_" ;
        }
    }
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            SetCursorPosition((2*9+1)+6*j,9+i);
            cout << "|" << endl;
        }
    }
    print_word_score(29,10);
    print_word_largest_number(25,13);
}
