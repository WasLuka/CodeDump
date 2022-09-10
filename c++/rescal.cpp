#include <iostream>

int pow(int num, int potency)
{
    int out = num;
    for (int i = 1; i < potency; i++)
    {
        out *= num;
    }
    if (potency == 0)
    {
        return 1;
    }
    else
    {
        return out;
    }
}

int values(std::string color)
{
    if (color == "black")
    {
        return 0;
    }
    else if (color == "brown")
    {
        return 1;
    }
    else if (color == "red")
    {
        return 2;
    }
    else if (color == "orange")
    {
        return 3;
    }
    else if (color == "yellow")
    {
        return 4;
    }
    else if (color == "green")
    {
        return 5;
    }
    else if (color == "blue")
    {
        return 6;
    }
    else if (color == "purple")
    {
        return 7;
    }
    else if (color == "grey")
    {
        return 8;
    }
    else if (color == "white")
    {
        return 9;
    }
    else if (color == "gold")
    {
        return -1;
    }
    else if (color == "silver")
    {
        return -2;
    }
    else
    {
        return 10;
    }
}

int tolerance(std::string color)
{
    if (color == "brown")
    {
        return 100;
    }
    else if (color == "red")
    {
        return 50;
    }
    else if (color == "green")
    {
        return 200;
    }
    else if (color == "blue")
    {
        return 400;
    }
    else if (color == "purple")
    {
        return 1000;
    }
    else if (color == "gold")
    {
        return 20;
    }
    else if (color == "silver")
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::string color[5];
    int rnum, tol;
    int j = 0, value = 0;

    std::cout << "How many colors does the resistor have?[3/4/5] ";
    std::cin >> rnum;
    std::cout << "Colors: ";

    if (rnum == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            std::cin >> color[i];
        }
        for (int i = 2; i > -1; i--)
        {
            if (values(color[j]) != 10)
            {
                value += values(color[j]) * pow(10, i);
                j++;
            }
            else if (color[j] != "black")
            {
                std::cout << "band " << j + 1 << " is wrong please insert it again: ";
                std::cin >> color[j];
                i++;
            }
        }
    }
    else if (rnum == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cin >> color[i];
        }
        for (int i = 1; i > -1; i--)
        {
            if (values(color[j]) != 10)
            {
                value += values(color[j]) * pow(10, i);
                j++;
            }
            else if (color[j] != "black")
            {
                std::cout << "band " << j + 1 << " is wrong please insert it again: ";
                std::cin >> color[j];
                i++;
            }
        }
    }
    else if (rnum == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            std::cin >> color[i];
        }
        for (int i = 1; i > -1; i--)
        {
            if (values(color[j]) != 10)
            {
                value += values(color[j]) * pow(10, i);
                j++;
            }
            else if (color[j] != "black")
            {
                std::cout << "band " << j + 1 << " is wrong please insert it again: ";
                std::cin >> color[j];
                i++;
            }
        }
    }
    else
    {
        std::cout << "Wrong number of bands try again!" << std::endl;
        main();
    }

    while (true)
    {
        if (values(color[j]) != 10)
        {
            value *= pow(10, values(color[j]));
            break;
        }
        else
        {
            std::cout << "band " << j + 1 << " is wrong please insert it again: ";
            std::cin >> color[j];
        }
    }
    j++;

    while (true)
    {
        if (tolerance(color[j]) != 0)
        {
            tol = value / tolerance(color[j]);
            break;
        }
        else
        {
            std::cout << "band " << j + 1 << " is wrong please insert it again: ";
            std::cin >> color[j];
        }
    }

    std::cout << value << " " << tol;
}