#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double function (double x);
double ledlook (double x);

int main() {
    system("chcp 65001");
    system("cls");

    double eps = 0.0001, a, b, x0, x, i = 1;
    
    while (1) {
        
        cout << "Введите значения для a and b:" << endl;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << endl;

        if (function(a) * function(b) < 0) { break; }
        else if (function(a) * function(b) > 0) { cout << "Пожалуйста, повторите попытку..." << endl; }
    }

    x = (a + b) / 2;
    do
    {
        x0 = x;
        x = ledlook(x0);
        cout << "Значение x = " << x << endl;
        i++;
    } while (fabs(x - x0) > eps);
    cout << "Конечное значение x = " << x << endl << "Номер итерации = " << i;
    return 0;
}

double function (double x) {
    double f;
     f = (sin(pow(x, 2) + 3)) + ((pow(sin(x), 2)) / 2);
    return f;
}

double ledlook (double x) {
    double f2;
    f2 = x + 0.25 * (sin(pow(x, 2) + 3)) + ((pow(sin(x), 2)) / 2);
    return f2;
}
