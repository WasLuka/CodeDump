#include <iostream>
using namespace std;

int main(){
    cout << "Choose a beverage Coke(1), Water(2), Sprite(3), Fanta(4) or pepsi(5)\n";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            cout << "Here is your coke";
            break;
        case 2:
            cout << "Here is your water";
            break;
        case 3:
            cout << "Here is your sprite";
            break;
        case 4:
            cout << "Here is your fanta";
            break;
        case 5:
            cout << "Here is your pepsi";
            break;
        default:
            cout << "Error. choice was not valid, here is your money back.";
            break;
    }
    return 0;
}