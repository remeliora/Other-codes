#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int n,s,p,k;
    int num = 0;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Enter k:" << endl;
    cin >> k;
    bool condition = true;
    while (condition) {
        if ((k >= 2) && (k <= 36)) {
            condition = false;
        }
        else {
            cout << "Repeat the Enter" << endl;
            cin >> k;
        }
    }
    while (n > 0) {
        p = n % 10;
        n = n / 10;
        num += p * pow(k, s);
        s++;
    }
    cout << "Notation in decimal system: " << num << endl;
    
    return 0;
}