#include <windows.h>
#include <iostream>

int main()
{   
    int x,y;

    system("mode " + y + ',' + x);//resize the window to be able to change the buffer size
    HANDLE m_hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT m_lpConsoleWindow = {0,0,y,x};

    SetConsoleWindowInfo(m_hConsoleHandle, true, &m_lpConsoleWindow);    

    system("pause");
}