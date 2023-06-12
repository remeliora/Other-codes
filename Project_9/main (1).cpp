//реализация метода половинного деления

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
	
double function(double x);//реализация функции

int main() {
    system("chcp 65001");
    system("cls");

    double eps = 0.0001, a, q, x, b, r, c, d, i = 0;//обЪявление епсилон и переменных
    cout << "Введите значения для a и b:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << endl;

    while (fabs(a - b) > eps) {//если разность по модулю a и b больше епсилон, то выполняется цикл while
        c = (a + b) / 2;//вычисление середины отрезка

        if (function(a) * function(b) > 0) {
            cout << "На промежутке нет значений" << endl;
            break;
        }

        i++;
        cout << "Номер итерации = " << i << endl;
        cout << "Новое a = " << a << endl;
        cout << "c = " << c << endl;
        cout << "b = " << b << endl;
        cout << "Значение функции из c = " << function(c) << endl;
        cout << "Значение функции из a = " << function(a) << endl;
        d = function(a) * function(c);
        cout << "Значение D = f(c) * f(a) = " << d << endl;
        cout << endl;

        if (d > 0) { a = c; }
        else if (d < 0) { b = c; }
    }
    x = (a + b) / 2;
    cout << "x = " << x << endl;
    system ("pause");
    return 0;
}

double function(double x) {
    double f;
    f = (sin ( pow(x,2) + 3)) + (( pow(sin(x),2)) / 2);
    return f;
}