#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    srand (time(NULL));

    int number = rand() % 100 + 1;
    int guess;
    std::cout << number << std::endl;
    std::cout << "Guess a number: ";

    while (1){
    
        std::cin >> guess;
        
        if (guess < number){
            std::cout << "Too low guess again: ";
        }
        else if (guess == number){
            std::cout << "Congratulations You guessed the number!" << std::endl;
            break;
        }
        else {
            std::cout << "Too high guess again";
        }
    }
    
    std::cout << "Dou you want to guess again? [y/n]";
    std::string answer;
    std::cin >> answer;
    if (answer == "y"){
        std::cout << "Here we go again" << std::endl;
        main();
    }
    else {
        std::cout << "Goodbye";
    }
}   