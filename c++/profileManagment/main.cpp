#include <iostream>
#include <string>
#include <fstream>
#include "admin.h"

using std::ios;


main()
{
    std::fstream myFile;
    std::string password,command,name,pass,role;
    int balance,deposit;
    
    logout:
    std::cout << "Enter your account name: ";
    std::cin >> name;

    myFile.open(name+".txt", ios::in);
    myFile >> balance;
    myFile >> pass;
    myFile >> role;
    myFile.close();
    while (1)
    {
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
                    goto exit;
                }
                if (command == "create" && role == "admin")
                {
                    create();
                }
                else if (command == "create" && role != "admin")
                {
                    std::cout << "You do not have admin priviliges\n";
                }
                if (command == "remove" && role == "admin")
                {
                    remove(pass);
                }
                else if (command == "remove" && role != "admin")
                {
                    std::cout << "You do not have admin priviliges\n";
                }
                if (command == "logout")
                {
                    std::cout << "Logging you out.\n";
                    goto logout;
                }
            }
        }
        else
        {
            if (password == "exit")
            {
                break;
            }
        }
    }
    exit:
    myFile.open(name+".txt", ios::out);
    myFile << balance << "\n";
    myFile << pass << "\n";
    myFile << role;
    myFile.close();
    return 0;
}