#include <iostream>
#include "OPI_1.h"

int main () {
    system("chcp 65001");
    system("cls");

    Array A;
    std::cout << "Введите количество элементов массива: ";
    A.Write_NumOfArrElem();
    A.Exercise_1();
    std::cout << std::endl << "Вывод массива слов:" << std::endl;
    A.PrintOriginalArray();
    A.Exercise_2();
    A.Exercise_3();
    A.PrintOriginalArray();
    std::cout << std::endl << std::endl << "Введите число для обрезки слов: ";
    A.Write_LenOfWord();
    A.Exercise_4();
    std::cout << "Изначальный массив: " << std::endl;
    A.PrintOriginalArray();
    std::cout << std::endl << "Преобразованный массив: " << std::endl;
    A.PrintConvertedArray();

    return 0;
}