#include "tools.h"
#include "control.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>

void print_pop(int placeChosen, int pop)
{
    if (placeChosen == 0)
        SetCursorPosition(19*2,19);
    else if (placeChosen == 1)
        SetCursorPosition(10*2,10);
    else if (placeChosen == 2)
        SetCursorPosition(13*2,10);
    else if (placeChosen == 3)
        SetCursorPosition(16*2,10);
    else if (placeChosen == 4)
        SetCursorPosition(19*2,10);
    else if (placeChosen == 5)
        SetCursorPosition(10*2,13);
    else if (placeChosen == 6)
        SetCursorPosition(13*2,13);
    else if (placeChosen == 7)
        SetCursorPosition(16*2,13);
    else if (placeChosen == 8)
        SetCursorPosition(19*2,13);
    else if (placeChosen == 9)
        SetCursorPosition(10*2,16);
    else if (placeChosen == 10)
        SetCursorPosition(13*2,16);
    else if (placeChosen == 11)
        SetCursorPosition(16*2,16);
    else if (placeChosen == 12)
        SetCursorPosition(19*2,16);
    else if (placeChosen == 13)
        SetCursorPosition(10*2,19);
    else if (placeChosen == 14)
        SetCursorPosition(13*2,19);
    else if (placeChosen == 15)
        SetCursorPosition(16*2,19);
    cout << pop;
}

int draw_GameOver(int score)
{
    // game over board
    SetColor(14);
    Sleep(500);
    SetCursorPosition(10*2, 8);
    cout << "------------------------------------------" ;
    Sleep(30);
    SetCursorPosition(9*2, 9);
    cout << " |               Game Over !!!              |" ;
    Sleep(30);
    SetCursorPosition(9*2, 10);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 11);
    cout << " |              Sorry! You loss:(           |" ;
    Sleep(30);
    SetCursorPosition(9*2, 12);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 13);
    cout << " |             You score:                   |" ;
    SetCursorPosition(24*2, 13);
    cout << score ;
    Sleep(30);
    SetCursorPosition(9*2, 14);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 15);
    cout << " |       Do you want to play again?         |" ;
    Sleep(30);
    SetCursorPosition(9*2, 16);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 17);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 18);
    cout << " |Sure!     I would rather choose to study. |" ;
    Sleep(30);
    SetCursorPosition(9*2, 19);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(9*2, 20);
    cout << " |                                          |" ;
    Sleep(30);
    SetCursorPosition(10*2, 21);
    cout << "------------------------------------------" ;

    // add background color for "Sure"
    Sleep(100);
    SetCursorPosition(10*2, 18);
    SetBackColor();
    cout << "Sure!" ;
    SetCursorPosition(0, 31);

    // choose
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
            case 75: // left
                if (tmp_key > 1)
                {
                    SetCursorPosition(10*2, 18);
                    SetBackColor();
                    cout << "Sure!" ;
                    SetCursorPosition(15*2, 18);
                    SetColor(14);
                    cout << "I would rather choose to study." ;
                    --tmp_key;
                }
                break;
            case 77: // right
                if (tmp_key < 2)
                {
                    SetCursorPosition(15*2, 18);
                    SetBackColor();
                    cout << "I would rather choose to study." ;
                    SetCursorPosition(10*2, 18);
                    SetColor(14);
                    cout << "Sure!" ;
                    ++tmp_key;
                }
                break;
            case 13: // enter
                flag = true;
                break;
            default:
                break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }

    SetColor(14);
    switch (tmp_key)
    {
        case 1:
            return 1; // restart
        case 2:
            return 2; // exit
        default:
            return 1;
    }
}
