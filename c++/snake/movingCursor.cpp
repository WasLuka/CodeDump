#include <windows.h>
#include <conio.h>
#include <iostream>

int main()
{   
    int i = 0;
    short x = 0,y = 0;
    const short mX = 81, mY = 41;//max and min window size 
    const short mnX = 0, mnY = 0;//preffered max is odd for a perfect start in the middle
    char input;
    char consoleWriteChar = '$';
    char consoleClearChar = ' ';
    DWORD nNumberOfCharsToWrite = 1;
    COORD pos = {x,y};
    COORD lastPos;

    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);


    DWORD dwSize = 100;
    BOOL bVisible = FALSE;
    CONSOLE_CURSOR_INFO m_lpConsoleCursorInfo = {dwSize, bVisible};//disable cursor and set screen size to wanted one

    SetConsoleCursorInfo(m_hConsoleHandle, &m_lpConsoleCursorInfo);

    system("mode 80,41");
    SMALL_RECT m_lpConsoleWindow = {0,0,mY,mX};

    SetConsoleWindowInfo(m_hConsoleHandle, true, &m_lpConsoleWindow);//to here

    start:;
    input = ' ';
    system("cls");

    x = mX/2;
    y = mY/2;
    pos = {x,y};
    lastPos = {x,(short)(y-1)};

    SetConsoleCursorPosition(m_hConsoleHandle, pos);
    WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);




    while(1)//main game loop
    {

        do
        {   
            if (i == 10)
            {   
                switch(input)
                {
                    case 'w':
                        if (y == mnY)
                        {
                            goto start;
                        }
                        else
                        {
                            y -= 1;
                        }
                        break;
                    case 'a':
                        if (x == mnX)
                        {
                            goto start;
                        }
                        else
                        {
                            x -= 1;
                        }
                        break;
                    case 's':
                        if (y == mY)
                        {
                            goto start;
                        }
                        else
                        {
                            y += 1;
                        }
                        break;
                    case 'd':
                        if (x == mX)
                        {
                            goto start;
                        }
                        else
                        {
                            x += 1;
                        }
                        break;
                    case 'm':
                        goto end;
                    default:
                        goto dowhile;
                }
                SetConsoleCursorPosition(m_hConsoleHandle, lastPos);
                WriteConsole(m_hConsoleHandle, &consoleClearChar, nNumberOfCharsToWrite, NULL, NULL);
            	
                lastPos = pos;
                pos = {x,y};
                SetConsoleCursorPosition(m_hConsoleHandle, pos);
                WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);
                i = 0;
            }
            if (i > 10)
            {
                i = 0;
            }
            dowhile:;
            Sleep(10);
            i++;
        }
        while(!kbhit());
        input = getch();
    }
    end:;
}