#include <iostream>

int say_hello(int n){
    while (n--){
        std::cout << "Hello" << std::endl;
    }
    return 0;
}

int multiplie(int n, int m){
    return n*m;
}

int half(int n){
    std::cout << n << std::endl;
    if (n>0){
        n /= 2;
        half(n);
    }
    return 0;
}

int main() {    
    int n,m;
    std::cin >> n;
    say_hello(n);
    
    std::cin >> n >> m;
    std::cout << multiplie(n, m) << std::endl;
    
    std::cin >> n;
    half(n);

    return 0;
}