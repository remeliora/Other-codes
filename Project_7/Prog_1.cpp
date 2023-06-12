#include <iostream>

int main() {
    double a, b, c, xn, xk, dx, F;   // аргументы a, b и c; 
                                        // xn - начало отрезка;
                                        // xk - конец отрезка;
                                        // dx - шаг;
                                        // F - результат функции
    int size;   // счётчик для кол-ва значений
    

    std::cin >> a >> b >> c >> xn >> xk >> dx;

    size = xk - xn;

    std::cout <<"-----------------\n";
    std::cout <<"    x   |   F    \n";
    std::cout <<"-----------------\n";

    for (double x = xn; x <= xk; x += dx) {
        if ((a < 0) && (x != 0)) {  // проверка на первое условие
            F = (a * (x * x) - (b * x) + c);
            std::cout << "  " << x << "\t|  ";
            std::cout << F << std::endl; 
        }
        else if ((x > 3) && (b == 0)) { // проверка на второе условие
                F = ((x - a) / (x - c));
                std::cout << "  " << x << "\t|  ";
                std::cout << F << std::endl;
            }
        if (c != 0) {   // проверка на третье условие (в остальных случаях)
                F = x / c;
                std::cout << "  " << x << "\t|  ";
                std::cout << F << std::endl;
        }
    }
    
    return 0;
}
