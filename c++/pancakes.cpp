#include <iostream>
using namespace std;

void sort(int array[10]){
    int temporary;
    int tamporary;
    int arrey[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int j=1;j<11;j++){
        for (int i=0;i<10-j;i++){
            
            if (array[i]>array[i+1]){
                temporary = array[i];
                array[i] = array[i+1];
                array[i+1] = temporary;
                
                tamporary = arrey[i];
                arrey[i] = arrey[i+1];
                arrey[i+1] = tamporary;
            }
        }
    }
    for (int i=0;i<10;i++){
        cout << "Person " << arrey[i] << ": ate " << array[i] << " Pancakes" << endl;
    }
}

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

    sort(people);

    return 0;
}