#include <iostream>
#include <windows.h>


int main()
{   
    short x,y;
    x = 0;
    y = 0;
    COORD m_ConsoleCursorPosition = {x,y};

    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO m_lpConsoleCursorInfo = {100,false};
    SetConsoleCursorInfo(m_hConsoleHandle, &m_lpConsoleCursorInfo);

    char consoleWriteChar = '$';
    DWORD nNumberOfCharsToWrite = 1;

    SetConsoleCursorPosition(m_hConsoleHandle, m_ConsoleCursorPosition);

    for (int i = 0;i < 10;i++)
    {   
        x = i;
        m_ConsoleCursorPosition = {x,y};
        WriteConsole(m_hConsoleHandle, &consoleWriteChar, nNumberOfCharsToWrite, NULL, NULL);
        SetConsoleCursorPosition(m_hConsoleHandle, m_ConsoleCursorPosition);
        Sleep(100);
    }
    system("pause");
}