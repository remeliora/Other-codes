#include <iostream>
#include <cmath>
using namespace std;
 
// определяем функцию 
double MyAtan( double x, double epsilon ) {
    double s = 0; // Тут копим сумму
    double an; // Тут храним N-ый член ряда
    int n;
    n = 0; // начальное значение n
    an = x; // начальное значение an
    while ( fabs(an) > epsilon )
// Суммировать будем пока член ряда an не станет достаточно маленьким по модулю
    {
        s += an; // суммируем очередной член ряда
        n++; // переходим к следующему члену
        an *= -x * x * ( 2. * n - 1. ) / ( 2. * n + 1. ); // пересчитываем a(n) через a(n-1)
    }
    return s; // получившаяся сумма
}
 
int main() {
 
    // ряд atan(x) сходится только при диапазоне значений x от -1 до 1
    double x = 0.5;
    cout << atan( x ) << endl; // для проверки используем стандартную функцию
    cout << MyAtan( x, 0.000001 ) << endl; // вызываем функцию
 
    return 0;
}