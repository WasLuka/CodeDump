#include <iostream>
#include <fstream>
#include <string>

using std::ios;

int create()
{
    std::fstream myAdmin;
    std::string name,role,password;

    std::cout << "Creating profile please enter account name: ";
    std::cin >> name;
    std::cout << "Please enter account role[customer/admin]: ";
    std::cin >> role;
    std::cout << "Please enter a password for the account: ";
    std::cin >> password;

    myAdmin.open(name+".txt", ios::out);
    myAdmin << 0 << "\n";
    myAdmin << password << "\n";
    myAdmin << role;
    myAdmin.close();
    
    return 0;
}

int remove(std::string pass)
{
    std::fstream myAdmin;
    std::string name,password;

    std::cout << "Please enter the account name: ";
    std::cin >> name;
    password:
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if (password == pass)
    {
    myAdmin.open(name+".txt", ios::out);
    myAdmin << "\n";
    myAdmin.close();
    }
    else{
        goto password;
    }
    return 0;
}