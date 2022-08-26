#include <iostream>
using namespace std;

int main(){
    int i = 0;
    while (i < 10){
        cout << "Choose a number that isn't " << i << ": ";
        int number;
        cin >> number;
        if (number == i){
            cout << "Hey! you weren't supposed to enter 5!";
            break;
        }
        i++;
        
    }
    cout << "Wow, you're more patient then I am, you win";
    return 0;
}