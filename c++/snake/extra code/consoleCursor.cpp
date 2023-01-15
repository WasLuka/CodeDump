#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <random>

int main()
{
    short x = 0,y = 0;//initializing all the needed values and clearing the screen
    short rX, rY;
    char input;
    char consoleChar ='$';
    char consoleFoodChar = '@';
    char clearConsoleChar = ' ';
    DWORD nNumberOfCharsToWrite = 1;
    COORD pos = {x, y};
    COORD randomPos;

    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//disable the cursor visibility
    DWORD dwSize = 100;
    BOOL bVisible = FALSE;
    CONSOLE_CURSOR_INFO m_lpConsoleCursorInfo = {dwSize, bVisible};

    SetConsoleCursorInfo(m_hConsoleHandle, &m_lpConsoleCursorInfo);

    srand(time(0));

    system("cls");//clear screen for any errors or past use of the terminal
    
    rX = rand() % 21;
    rY = rand() % 11;
    randomPos = {rX,rY};

    SetConsoleCursorPosition(m_hConsoleHandle, randomPos);
    WriteConsole(m_hConsoleHandle, &consoleFoodChar, nNumberOfCharsToWrite, NULL, NULL);

    while(1)
    {

    reading:;
    
    do
    {

    } while (!kbhit());
    input = getch();

    switch(input)   //all the commands
    {
        case 'w':   //move cursor up
            if (y > 0)
            {
                y -= 1;
            }
            break;
        case 'a':   //move cursor down
            if (x > 0)
            {
                x -= 1;
            }
            break;
        case 's':   //move cursor left
            y += 1;
            break;
        case 'd':   //move cursor right
            x += 1;
            break;
        case 'm':   //end the program
            goto end;
            break;
        default:
            goto reading;
    }

    //clear the last character before prinitng the new one to get rid of flicker when clearing the screen
    SetConsoleCursorPosition(m_hConsoleHandle, pos);
    WriteConsole(m_hConsoleHandle, &clearConsoleChar, nNumberOfCharsToWrite, NULL, NULL);
    
    //set the new cursor position based on user input
    pos = {x, y};
    SetConsoleCursorPosition(m_hConsoleHandle, pos);
    WriteConsole(m_hConsoleHandle, &consoleChar, nNumberOfCharsToWrite, NULL, NULL);
    
    if (x == rX && y == rY)
    {
        rX = rand() % 21;
        rY = rand() % 11;
        randomPos = {rX,rY};
        SetConsoleCursorPosition(m_hConsoleHandle, randomPos);
        WriteConsole(m_hConsoleHandle, &consoleFoodChar, nNumberOfCharsToWrite, NULL, NULL);
        SetConsoleCursorPosition(m_hConsoleHandle, pos);
    }

    }
    end:;
}