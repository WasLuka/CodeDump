#include <iostream>
#include <conio.h>
#include "windows.h"

int main()
{
    int count = 1;
    char userInput,turn;
    char gameTable[3][3] =
    {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };

    while(count < 10)
    {
        if (count++ % 2 == 0) 
        {
            turn = 'x';
        }
        else
        {
            turn = 'o';
        }
        std::cout << "It's " << turn << " turn:" << std::endl;

        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                std::cout << gameTable[i][j] << " ";
            }
            std::cout << std::endl;
        }

        invalidInput:;
        while(!kbhit());
        userInput = getch();
        switch(userInput)
        {
            case '7':
                if(gameTable[0][0] == '0')
                {
                    gameTable[0][0] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '8':
                if(gameTable[0][1] == '0')
                {
                    gameTable[0][1] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '9':
                if(gameTable[0][2] == '0')
                {
                    gameTable[0][2] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;

            case '4':
                if(gameTable[1][0] == '0')
                {
                    gameTable[1][0] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '5':
                if(gameTable[1][1] == '0')
                {
                    gameTable[1][1] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '6':
                if(gameTable[1][2] == '0')
                {
                    gameTable[1][2] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;

            case '1':
                if(gameTable[2][0] == '0')
                {
                    gameTable[2][0] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '2':
                if(gameTable[2][1] == '0')
                {
                    gameTable[2][1] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;
            case '3':
                if(gameTable[2][2] == '0')
                {
                    gameTable[2][2] = turn;
                }
                else
                {
                    goto invalidInput;
                }
                break;   
        }
        
        for (int i = 0; i < 3; i++)
        {
            if (gameTable[i][0] == gameTable[i][1] && gameTable[i][1] == gameTable[i][2] && gameTable[i][1] != '0')
            {
                std::cout << "Congrartulations " << gameTable[i][1] << " won!\n";
                goto end;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (gameTable[0][i] == gameTable[1][i] && gameTable[1][i] == gameTable[2][i] && gameTable[1][i] != '0')
            {
                std::cout << "Congrartulations " << gameTable[1][i] << " won!\n";
                goto end;
            }
        }
        if (gameTable[0][0] == gameTable[1][1] && gameTable[1][1] == gameTable[2][2] && gameTable[1][1] != '0')
        {
            std::cout << "Congrartulations " << gameTable[1][1] << " won!\n";
            goto end;
        }
        if (gameTable[0][2] == gameTable[1][1] && gameTable[1][1] == gameTable[2][0] && gameTable[1][1] != '0')
        {
            std::cout << "Congrartulations " << gameTable[1][1] << " won!\n";
            goto end;
        }
        
        system("cls");

    }
    end:;
    system("pause");
    return 0;
}