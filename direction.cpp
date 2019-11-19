#include "tools.h"
#include "direction.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <unistd.h>
#include <ctype.h>
#include <conio.h>

int ChangeDirection_arrow(int content[], int score)
{
    char ch;
    ch = _getch();
    if (_kbhit())
    {
        switch (ch)
        {
            case -32:
                ch = _getch();
                switch (ch)
                {
                    case 72:    // up
                        score = up(content,score);
                        break;
                    case 80:    // down
                        score = down(content,score);
                        break;
                    case 77:    // right
                        score = right(content,score);
                        break;
                    case 75:    // left
                        score = left(content,score);
                        break;
                    default:
                        break;
                }
                return score;
            default:
                return score;
        }
    }
    return score;
}

int up(int content[], int score)
{
    for (int runtime = 0; runtime < 4; runtime++)
    {
        for (int j = 2; j > 0; j--)
        {
            for (int i = 5+4*j; i < 8+4*j; i++)
            {
                if (content[i] != 0 && content[i-4] == 0)
                {
                    content[i-4] = content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4), 13+3*j);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4), 10+3*j);
                    cout << content[i-4];
                }
            }
        }
        if (content[0] != 0 && content[12] == 0)
        {
            content[12] = content[0];
            content[0] = 0;

            SetCursorPosition(38,19);
            cout << "     ";
            SetCursorPosition(38,16);
            cout << content[12];
        }
        if (content[12] != 0 && content[8] == 0)
        {
            content[8] = content[12];
            content[12] = 0;

            SetCursorPosition(38,16);
            cout << "     ";
            SetCursorPosition(38,13);
            cout << content[8];
        }
        for (int i = 5; i < 8; i++)
        {
            if (content[i] != 0)
            {
                if (content[i-4] == 0)
                {
                    content[i-4] = content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4), 13);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4), 10);
                    cout << content[i-4];
                }
                else if (content[i-4] == content[i])
                {
                    score += content[i-4];

                    content[i-4] += content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4), 13);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4), 10);
                    cout << content[i-4];
                }

            }
        }
        if (content[8] != 0)
        {
            if (content[4] == 0)
            {
                content[4] = content[8];
                content[8] = 0;

                SetCursorPosition(38,13);
                cout << "     ";
                SetCursorPosition(38,10);
                cout << content[4];
            }
            else if (content[4] == content[8])
            {
                score += content[4];

                content[4] += content[8];
                content[8] = 0;

                SetCursorPosition(38,13);
                cout << "     ";
                SetCursorPosition(38,10);
                cout << content[4];
            }
        }
        if (content[12] != 0 && content[8] == content[12])
        {
            score += content[8];

            content[8] = content[8] + content[12];
            content[12] = 0;

            SetCursorPosition(38,16);
            cout << "     ";
            SetCursorPosition(38,13);
            cout << content[8];
        }
        if (content[0] != 0 && content[12] == content[0])
        {
            score += content[12];

            content[12] = content[12] + content[0];
            content[0] = 0;

            SetCursorPosition(38,19);
            cout << "     ";
            SetCursorPosition(38,16);
            cout << content[12];
        }
        for (int j = 1; j < 3; j++)
        {
            for (int i = 5+4*j; i < 8+4*j; i++)
            {
                if (content[i] != 0 && content[i-4] == content[i])
                {
                    score += content[i-4];

                    content[i-4] = content[i-4] + content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4), 13+3*j);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4), 10+3*j);
                    cout << content[i-4];
                }
            }
        }
    }
    return score;
}

int down(int content[], int score)
{
    for (int runtime = 0; runtime < 4; runtime++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int i = 4*j+1; i < 4+4*j; i++)
            {
                if (content[i] != 0 && content[i+4] == 0)
                {
                    content[i+4] = content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4),10+3*j);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4),13+3*j);
                    cout << content[i+4];
                }
            }
        }
        for (int j = 1; j < 3; j++)
        {
            if (content[4*j] != 0 && content[4+4*j] == 0)
            {
                content[4+4*j] = content[4*j];
                content[4*j] = 0;

                SetCursorPosition(38,7+3*j);
                cout << "     ";
                SetCursorPosition(38,10+3*j);
                cout << content[4+4*j];
            }
        }
        for (int i = 9; i < 12; i++)
        {
            if (content[i] != 0)
            {
                if (content[i+4] == 0)
                {
                    content[i+4] = content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4),16);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4),19);
                    cout << content[i+4];
                }
                if (content[i+4] == content[i])
                {
                    score += content[i+4];

                    content[i+4] += content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4),16);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4),19);
                    cout << content[i+4];
                }
            }
        }
        if (content[12] != 0)
        {
            if (content[0] == 0)
            {
                content[0] = content[12];
                content[12] = 0;

                SetCursorPosition(38,16);
                cout << "     ";
                SetCursorPosition(38,19);
                cout << content[0];
            }
            else if (content[0] == content[12])
            {
                score += content[0];

                content[0] += content[12];
                content[12] = 0;

                SetCursorPosition(38,16);
                cout << "     ";
                SetCursorPosition(38,19);
                cout << content[0];
            }
        }
        for (int j = 2; j > 0; j--)
        {
            if (content[4*j] != 0 && content[4+4*j] == content[4])
            {
                score += content[4+4*j];

                content[4+4*j] = content[4+4*j] + content[4*j];
                content[4*j] = 0;

                SetCursorPosition(38,7+3*j);
                cout << "     ";
                SetCursorPosition(38,10+3*j);
                cout << content[4+4*j];
            }
        }
        for (int j = 2; j >= 0; j--)
        {
            for (int i = 1+4*j; i < 4+4*j; i++)
            {
                if (content[i] != 0 && content[i+4] == content[i])
                {
                    score += content[i+4];

                    content[i+4] = content[i+4] + content[i];
                    content[i] = 0;

                    SetCursorPosition(14 + 6*(i%4),10+3*j);
                    cout << "     ";
                    SetCursorPosition(14 + 6*(i%4),13+3*j);
                    cout << content[i+4];
                }
            }
        }
    }
    return score;
}

int left(int content[], int score)
{
    for (int runtime = 0; runtime < 4; runtime++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (content[4*i] != 0 && content[4*i-1] == 0)
            {
                content[4*i-1] = content[4*i];
                content[4*i] = 0;

                SetCursorPosition(38,7+3*i);
                cout << "     ";
                SetCursorPosition(32,7+3*i);
                cout << content[4*i-1];
            }
        }
        if (content[0] != 0 && content[15] == 0)
        {
            content[15] = content[0];
            content[0] = 0;

            SetCursorPosition(38,19);
            cout << "     ";
            SetCursorPosition(32,19);
            cout << content[15];
        }
        for (int j = 1; j < 3; j++)
        {
            for (int i = 1; i < 5; i++)
            {
                if (content[4*i-j] != 0 && content[4*i-j-1] == 0)
                {
                    content[4*i-j-1] = content[4*i-j];
                    content[4*i-j] = 0;

                    SetCursorPosition(38-6*j,7+3*i);
                    cout << "     ";
                    SetCursorPosition(38-6*(j+1),7+3*i);
                    cout << content[4*i-j-1];
                }
            }
        }
        for (int j = 2; j > 0; j--)
        {
            for (int i = 1; i < 5; i++)
            {
                if (content[4*i-j] != 0 && content[4*i-j-1] == content[4*i-j])
                {
                    score += content[4*i-j-1];

                    content[4*i-j-1] = content[4*i-j-1] + content[4*i-j];
                    content[4*i-j] = 0;

                    SetCursorPosition(38-6*j,7+3*i);
                    cout << "     ";
                    SetCursorPosition(38-6*(j+1),7+3*i);
                    cout << content[4*i-j-1];
                }
            }
        }
        if (content[0] != 0 && content[15] == content[0])
        {
            score += content[15];

            content[15] = content[15] + content[0];
            content[0] = 0;

            SetCursorPosition(38,19);
            cout << "     ";
            SetCursorPosition(32,19);
            cout << content[15];
        }
        for (int i = 1; i < 4; i++)
        {
            if (content[4*i] != 0 && content[4*i-1] == content[4*i])
            {
                score += content[4*i-1];

                content[4*i-1] = content[4*i-1] + content[4*i];
                content[4*i] = 0;

                SetCursorPosition(38,7+3*i);
                cout << "     ";
                SetCursorPosition(32,7+3*i);
                cout << content[4*i-1];
            }
        }
    }
    return score;
}

int right (int content[], int score)
{
    for (int runtime = 0; runtime < 4; runtime++)
    {
        for (int j = 1; j < 3; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (content[4*i+j] != 0 && content[4*i+j+1] == 0)
                {
                    content[4*i+j+1] = content[4*i+j];
                    content[4*i+j] = 0;

                    SetCursorPosition(14+6*j,10+3*i);
                    cout << "     ";
                    SetCursorPosition(20+6*j,10+3*i);
                    cout << content[4*i+j+1];
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (content[4*i+3] != 0)
            {
                if (content[4*i+4] == 0)
                {
                    content[4*i+4] = content[4*i+3];
                    content[4*i+3] = 0;

                    SetCursorPosition(32,10+3*i);
                    cout << "     ";
                    SetCursorPosition(38,10+3*i);
                    cout << content[4*i+4];
                }
                else if (content[4*i+4] == content[4*i+3])
                {
                    score += content[4*i+4];

                    content[4*i+4] = content[4*i+4] + content[4*i+3];
                    content[4*i+3] = 0;

                    SetCursorPosition(32,10+3*i);
                    cout << "     ";
                    SetCursorPosition(38,10+3*i);
                    cout << content[4*i+4];
                }
            }
        }
        if (content[15] != 0)
        {
            if (content[0] == 0)
            {
                content[0] = content[15];
                content[15] = 0;

                SetCursorPosition(32,19);
                cout << "     ";
                SetCursorPosition(38,19);
                cout << content[0];
            }
            else if (content[0] == content[15])
            {
                score += content[0];

                content[0] += content[15];
                content[15] = 0;

                SetCursorPosition(32,19);
                cout << "     ";
                SetCursorPosition(38,19);
                cout << content[0];
            }
        }
        for (int j = 2; j > 0; j--)
        {
            for (int i = 0; i < 4; i++)
            {
                if ((content[4*i+j] != 0) && (content[4*i+j+1] == content[4*i+j]))
                {
                    score += content[4*i+j+1];

                    content[4*i+j+1] = content[4*i+j+1] + content[4*i+j];
                    content[4*i+j] = 0;

                    SetCursorPosition(14+6*j,10+3*i);
                    cout << "     ";
                    SetCursorPosition(20+6*j,10+3*i);
                    cout << content[4*i+j+1];
                }
            }
        }
    }
    return score;
}

