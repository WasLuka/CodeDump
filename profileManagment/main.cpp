#include <iostream>
#include <string>
#include <fstream>

using std::ios;

main()
{
    std::fstream myFile;
    std::string password,command,name,pass;
    int balance,deposit;
    
    std::cout << "Enter your account name: ";
    std::cin >> name;

    myFile.open(name+".txt", ios::in);
    myFile >> balance;
    myFile >> pass;
    myFile.close();

    std::cout << "Please enter your pasword: ";
    std::cin >> password;

    if (password == pass)
    {
        std::cout << "Correct password you are in!\n";
        while (1)
        {
            std::cout << "> ";
            std::cin >> command;

            if (command == "balance")
            {
                std::cout << "your balance is " << balance << "\n";
            }
            if (command == "deposit")
            {
                std::cout << "Enter the amount you want to deposit: ";
                std::cin >> deposit;
                balance += deposit;
                std::cout << "Your balance is " << balance << "\n";
            }
            if (command == "withdraw")
            {
                std::cout << "Enter the amount you want to withdraw: ";
                std::cin >> deposit;
                balance -= deposit;
                std::cout << "Your balance is " << balance << "\n";
            }
            if (command == "exit")
            {
                break;
            }
        }
    }
    else
    {
        main();
    }

    myFile.open(name+".txt", ios::out);
    myFile << balance << "\n";
    myFile << pass;
    myFile.close();
    return 0;
}