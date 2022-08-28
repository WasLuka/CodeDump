#include <iostream>

int x = 0;
int y = 101;
int count = 0;

int main() {
    std::string answer;
    
    count++;

    int middle = (y-x)/2;

    std::cout << x+middle << std::endl;
    std::cin >> answer;

    if (answer == "yes"){
        std::cout << "It took me " << count << " trys!";
    }
    else if (answer == "h"){
        y-= middle;
        main();
    }
    else if (answer == "l"){
        x+= middle;
        main();
    }
}
