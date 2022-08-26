#include <iostream>
using namespace std;

int main() {

    int grade;
    cout << "Enter your grade here: ";
    cin >> grade;
    if (grade == 100){
        cout << "You got a perfect score! \n";
    }
    else if (grade > 89){
        cout << "You got an A! \n";
    }
    else if (grade > 79){
        cout << "You got a B! \n";
    }
    else if (grade >  69){
        cout << "You got a C \n";
    }
    else if (grade > 59){
        cout << "You got a D \n";
    }
    else{
        cout << "You got a F \n";
    }
    return 0;
}