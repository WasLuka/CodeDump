//name of the file is Strings are your friends, until they betray you
#include <iostream>
#include <string>

int main(){
    std::string fname,lname,name;
    int t;

    std::cout << "What is your full name? ";
    std::cin >> fname >> lname;

    name = fname+" "+lname;
    fname = name;

    std::cout << name << std::endl;

    t = name.length();
    while (t--){
        switch (name[t]){

            case 'a':
                name[t] = 'z';
                break;
            case 'e':
                name[t] = 'z';
                break;
            case 'i':
                name[t] = 'z';
                break;
            case 'o':
                name[t] = 'z';
                break;
            case 'u':
                name[t] = 'z';
                break;
            default:
                break;
        }
        
    }
    std::cout << name << std::endl;
    t = fname.length();
    while(t--){
        std::cout << fname[t];
    }

    return 0;
}