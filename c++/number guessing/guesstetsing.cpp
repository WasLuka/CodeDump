#include <iostream>

int count = 0;
int x = 0;
int y = 1001;
int i = 1;

int main(){
    count++;

    int middle = (y-x)/2;
    while (i<1001){
    
    if (x+middle == i){
        std::cout << std::endl << count << " " << i;
        i++;
        x = 0;
        y = 1001;
        count = 0;
        main();

    }
    else if (x+middle > i){
        y-=middle;
        main();
    }
    else if (x+middle < i){
        x+= middle;
        main();
    }
    else {
        main();
    }
    
    }
    
    return 0;
    
    
}