#include <iostream>

int main(int argc, char** argv)
{
    start:;
    int result,middle;
    int x = 0,y = 101, count = 0;

    std::cout << "Tell me a number 1-100 and i will try to guess it!: ";
    std::cin >> result;

    while(1)
    {   
        count++;
        middle = (y - x) / 2;
        std::cout << middle+x << std::endl;
        if ((x+middle) > result)
        {
            if (middle > 1)
            {
                y -= middle;
            }
        }
        if (x+middle < result)
        {
            x += middle;
        }
        if (middle+x == result)
        {
            std::cout << "Found it in " << count << " trys!" << std::endl;
            system("pause");
            goto start;
        }
    }
}