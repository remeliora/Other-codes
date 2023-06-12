#include <iostream>
using namespace std;

int main() {
    int decimal, n, count;
    cin >> decimal;
    while(decimal) {
        decimal/=10;
        count++;
    }
    n = count;
    cout << n;
    return 0;
}