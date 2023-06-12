#include <iostream>

int fibonachi(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return fibonachi(number - 1) + fibonachi(number - 2);
}

int factorial(int i) {
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

int main() {
    system("chcp 65001");
    system("cls");

    int size; // количество чисел Фибоначи
    // int *mass = new int[size];
    // int number = 0;
    int number; // число, факториал которого необходимо найти; 
    

    std::cout << "Введите количество чисел Фибоначи: ";
    std::cin >> size;
    // std::cout << std::endl;
    // for (int i = 0; i < size; i++) {
    //     if (number == 0) {
    //         mass[0] = number;
    //     }
    //     else if (number == 1) {
    //         mass[1] = number;
    //     }
    //     else if (number > 1) {
    //         mass[i] = mass[number - 1] + mass[number - 2];
    //     }
    //     number++;
    // }
    
    std::cout << "Вывод всех числел Фибоначи, согласно заданному количеству:" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << fibonachi(i) << " ";
    }
    
    std::cout << std::endl << std::endl;

    std::cout << "Введите число, факториал которого необходимо вычислить: ";

    std::cin >> number;
    std::cout << "Факториал числа " << number << " равен " << factorial(number);

    return 0;
}