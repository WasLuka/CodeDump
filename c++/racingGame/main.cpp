#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include <conio.h>

std::string lane[7] = {"| | | |", "|Y| | |", "| |Y| |", "| | |Y|","|A| | |","| |A| |","| | |A|"};
int block[28] = {};
int y = 0;

int rdnRd();

int shiftRight()
{
    for (int i = 27;i > -1;i--)
    {   
        block[i] = block[i-1];
    }
    block[0] = rdnRd();
    return 0;
}

int rdnRd()
{
    int num = 0;

    num = rand() % 10 + 1;
    switch (num)
    {
        case 1:
            if (y == 0)
            {
                y = 1;
                return 4;
            }
        case 5:
            if (y == 0)
            {
                y = 1;
                return 5;
            }
        case 7:
            if (y == 0)
            {
                y = 1;
                return 6;
            }
    }
    return 0;
}

int main()
{
    int x, num, a,j;
    char c;

    x = 1;
    y = 0;
    for (int i = 0;i < 28;i++)
    {
        block[i] = 0;
    }

    srand(time(NULL));

    system("cls");

    while (1)//glavni loop
    {

        do
        {  
            j++; 
            if (block[27] == 4 || block[27] == 5 || block[27] == 6)//resetira y ko gre ovira iz terminala
            {
                y = 0;
            }

            for (int i = 0; i < 28; i++)
            {
                std::cout << lane[block[i]]<< std::endl;
            }

            std::cout << lane[x] << std::endl;
            shiftRight();
            //Sleep(1);
            system("cls");
        }   
        while (!kbhit());
        c = getch();

        switch (c)//filtriranje pritiskov tipkovnice z komandami
        {
            case 'a':
                if (x > 1)
                {
                    x--;
                }
                break;
            case 'd':
                if (x < 3)
                {
                    x++;
                }
                break;
            case 'm':
                goto end;
        }
    }
end:;
    return 0;
}