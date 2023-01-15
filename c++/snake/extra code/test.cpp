#include <iostream>
#include <windows.h>
#include <random>
#include <time.h>
#include <conio.h>

int main()
{    
    /*int i = 0;
    short x = 0,y = 0;
    const short mX = 81, mY = 41;//max and min window size 
    const short mnX = 0, mnY = 0;//preffered max is odd for a perfect start in the middle
    char input;
    char consoleWriteChar = '@';
    char consoleClearChar = 0x8;
    DWORD nNumberOfCharsToWrite = 1;
    DWORD dwMode = 0x0200;
    COORD pos = {x,y};
    COORD lastPos;

    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);


    DWORD dwSize = 100;
    BOOL bVisible = FALSE;
    CONSOLE_CURSOR_INFO m_lpConsoleCursorInfo = {dwSize, bVisible};//disable cursor and set screen size to wanted one

    SetConsoleCursorInfo(m_hConsoleHandle, &m_lpConsoleCursorInfo);

    system("mode 81,41");
    SMALL_RECT m_lpConsoleWindow = {0,0,mY,mX};

    SetConsoleMode(m_hConsoleHandle, dwMode);

    SetConsoleWindowInfo(m_hConsoleHandle, true, &m_lpConsoleWindow);//to here
    start:;

    input = ' ';
    system("cls");

    srand(time(0));


    while(1)
    {
        do
        {   
            sleep:;
            Sleep(10);
        }
        while(!kbhit());
        input = getch();
        
        wprintf(L"\x1b[1X");

        Sleep(1);
            if(input == 'm')
            { 
                x = rand() % mX-1;
                y = rand() % mY-1;
            }
            else{
                goto sleep;
            }
        Sleep(1);
        SetConsoleCursorPosition(m_hConsoleHandle, pos);
        wprintf(L"\x1b[1X");
        pos = {x,y};
        SetConsoleCursorPosition(m_hConsoleHandle, pos);
        WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);
    
    }*/
    int tailLength = 2;
    for(int i = tailLength;i>0;i--)
    {
        std::cout << i;
    }
}   
