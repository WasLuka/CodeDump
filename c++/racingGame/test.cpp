#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include <conio.h>
#include <string.h>

int block[28] = {};

int shiftRight()
{
    for (int i = 27;i > -1;i--)
    {   
        block[i] = block[i-1];
    }
    block[0] = 0;
    return 0;
}

int main() {

    int y;
    std::string lane[2] = {"| | | |","| |A| |"};

    for (int i = 0;i < 28;i++)
    {
        block[i] = 0;
    }
    y = 0;

    while (1)
    {   
        if (y == 0)//preveri če ni ovire na terminalu
        {
            block[0] = 1;
            y = 1;
        }
        if (block[27] == 1)//resetira y ko gre ovira iz terminala
        {
            y = 0;
        }
        for (int i = 0; i < 28;i++)
        {
            std::cout << lane[block[i]]<< std::endl;
        }
        shiftRight();
        Sleep(1);
        system("cls");
    }
}
