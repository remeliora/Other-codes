//Написать программу где пользователь вводит номер месяца программа выводит название месяца, 
//если номер не правильный, то выводится ошибка и предлагается заново ввести число
#include<iostream>
#include "function.cpp"
#include "function.h"

int main() {
    int num;
    std::cout << "Enter number: " << std::endl;
    std::cin >> num;
    seasonMonth(num);
    
    return 0;
}