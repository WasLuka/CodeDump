#include <iostream>
using namespace std;

//add a sorting algorithm that outputs every person based on how many pancakes they ate

int main(){
    int people[10];
    int mostnofp = 0, leastnofp = 0;
    for (int i = 0;i<10;i++){
        cout << "How many pancakes did person " << (i+1) << " eat? ";
        cin >> people[i];   
    }
    for (int i = 0;i<10;i++){
        if (people[i] > people[mostnofp]){
            mostnofp = i;
        }
        if (people[i] < people[leastnofp]){
            leastnofp = i;
        }
    }
    cout << "Person " << (mostnofp+1) << " ate the most pancakes " << people[mostnofp] << endl;
    cout << "person " << (leastnofp+1) << " ate the least pancakes " << people[leastnofp] << endl;



    return 0;
}