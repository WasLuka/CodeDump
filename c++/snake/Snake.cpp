#include <windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <random>

int main()
{   
    int i = 0;
    short x = 0,y = 0;
    short rX, rY;
    int sleep;
    int tailLength;
    short tailPos[1024][2];
    const short mX = 81, mY = 41;//max and min window size 
    const short mnX = 0, mnY = 0;//preffered max is odd for a perfect start in the middle
    char input;
    char lastInput;
    char consoleWriteChar = '$';
    char consoleFoodChar = '@';
    char consoleClearChar = ' ';
    DWORD nNumberOfCharsToWrite = 1;
    COORD pos = {x,y};
    COORD lastPos;
    COORD randomPos;

    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(0));

    DWORD dwSize = 100;
    BOOL bVisible = FALSE;
    CONSOLE_CURSOR_INFO m_lpConsoleCursorInfo = {dwSize, bVisible};//disable cursor and set screen size to wanted one

    SetConsoleCursorInfo(m_hConsoleHandle, &m_lpConsoleCursorInfo);

    system("mode 81,41");
    SMALL_RECT m_lpConsoleWindow = {0,0,mY,mX};

    SetConsoleWindowInfo(m_hConsoleHandle, true, &m_lpConsoleWindow);//to here


    /*
    std::cout << "How much pause do you want between moves?[100-5 is recommended][ms] ";  for future use not needed in testing wil be probbaly changed to difficulty
    std::cin >> sleep;
    */
    sleep = 10;

    start:;

    lastInput = ' ';
    input = ' ';
    tailLength = 1;

    system("cls");

    x = mX/2;
    y = mY/2;
    pos = {x,y};
    tailPos[0][0] = x;
    tailPos[0][1] = y;

    SetConsoleCursorPosition(m_hConsoleHandle, pos);
    WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);

    rX = rand() % 81;
    rY = rand() % 41;
    randomPos = {rX,rY};
    SetConsoleCursorPosition(m_hConsoleHandle, randomPos);
    WriteConsole(m_hConsoleHandle, &consoleFoodChar, nNumberOfCharsToWrite, NULL, NULL);
    SetConsoleCursorPosition(m_hConsoleHandle, pos);


    while(1)//main game loop
    {

        do
        {   
            
            wrongInput:;
            if (i == 10)
            {      
                switch(input)
                {
                    case 'w':
                        w:;
                        if (lastInput == 's')
                        {   
                            input = 's';
                            goto s;
                        }
                        if (y == mnY)
                        {
                            goto start;
                        }
                        else
                        {
                            y -= 1;
                            lastInput = input;
                        }
                        lastInput = input;
                        break;

                    case 'a':
                        a:;
                        if (lastInput == 'd')
                        {   
                            input = 'd';
                            goto d;
                        }
                        if (x == mnX)
                        {
                            goto start;
                        }
                        else
                        {
                            x -= 1;
                            lastInput = input;
                        }
                        lastInput = input;
                        break;

                    case 's':
                        s:;
                        if (lastInput == 'w')
                        {   
                            input = 'w';
                            goto w;
                        }
                        if (y == mY)
                        {
                            goto start;
                        }
                        else
                        {
                            y += 1;
                            lastInput = input;
                        }
                        lastInput = input;
                        break;

                    case 'd':
                        d:;
                        if(lastInput == 'a')
                        {   
                            input = 'a';
                            goto a;
                        }
                        if (x == mX)
                        {
                            goto start;
                        }
                        else
                        {
                            x += 1;
                            lastInput = input;
                        }
                        lastInput = input;
                        break;

                    case 'm':
                        goto end;

                    default:
                        if (lastInput != ' ' )
                        {
                            input = lastInput;
                            goto wrongInput;
                        }
                        goto noInput;//skip erasing and pasting the caracter to not flash it on the start
                }
                
                for(int j = tailLength;j > 0;j--)
                {
                    tailPos[j][0] = tailPos[j-1][0];
                    tailPos[j][1] = tailPos[j-1][1];
                }
                for(int j = 2;j < tailLength+1;j++)
                {
                    if(tailPos[j][0] == tailPos[0][0] && tailPos[j][1] == tailPos[0][1])
                    {
                        goto start;
                    }
                }

                lastPos = {tailPos[tailLength][0],tailPos[tailLength][1]};

                SetConsoleCursorPosition(m_hConsoleHandle, lastPos);
                wprintf(L"\x1b[1X");
            	
                pos = {x,y};
                tailPos[0][0] = x;
                tailPos[0][1] = y;
                SetConsoleCursorPosition(m_hConsoleHandle, pos);
                WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);
                i = 0;
            }
                noInput:;
            if (i > 10)
            {
                i = 0;
            }
            i++;
            if (x == rX && y == rY)
            {
                rX = rand() % 81;
                rY = rand() % 41;
                randomPos = {rX,rY};
                SetConsoleCursorPosition(m_hConsoleHandle, randomPos);
                WriteConsole(m_hConsoleHandle, &consoleFoodChar, nNumberOfCharsToWrite, NULL, NULL);
                SetConsoleCursorPosition(m_hConsoleHandle, pos);
                tailLength+= 1;
            }
            Sleep(sleep);
        }
        while(!kbhit());
        input = getch();
    }
    end:;
}