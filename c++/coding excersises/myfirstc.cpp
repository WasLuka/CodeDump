#include <iostream>
using namespace std;
//test
int main() {
    int n,t;
    cin >> t;
    for (int i = 0;i<t;i++){
        cin >> n;
        cout << (n *= n);
        cout << "\n";
    }
    return 0;
}