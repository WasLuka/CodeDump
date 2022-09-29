#include <iostream>

int main()
{
    int x, y;
    char e;
    char table[3][3] =
        {
            {'0', '0', '0'},
            {'0', '0', '0'},
            {'0', '0', '0'}};

    std::cout << "This is TicTacToe!\n";

    for (int m = 1; m < 10; m++)
    {

        std::cout << table[0][0] << " " << table[0][1] << " " << table[0][2] << "\n";
        std::cout << table[1][0] << " " << table[1][1] << " " << table[1][2] << "\n";
        std::cout << table[2][0] << " " << table[2][1] << " " << table[2][2] << "\n";

        if (m % 2 == 0)
        {
            std::cout << "Its [x] turn\n";
        x:
            std::cin >> y;
            std::cin >> x;

            if (table[y][x] == '0')
            {
                table[y][x] = 'x';
            }
            else
            {
                goto x;
            }
        }
        else
        {
            std::cout << "Its [o] turn\n";
        o:
            std::cin >> y;
            std::cin >> x;

            if (table[y][x] == '0')
            {
                table[y][x] = 'o';
            }
            else
            {
                goto o;
            }
        }
        system("cls");

        for (int i = 0; i < 3; i++)
        {
            if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][1] != '0')
            {
                std::cout << "Congrartulations " << table[i][1] << " won!\n";
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[1][i] != '0')
            {
                std::cout << "Congrartulations " << table[1][i] << " won!\n";
            }
        }
        if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[1][1] != '0')
        {
            std::cout << "Congrartulations " << table[1][1] << " won!\n";
        }
        if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[1][1] != '0')
        {
            std::cout << "Congrartulations " << table[1][1] << " won!\n";
        }
    }

    system("sleep");
}
