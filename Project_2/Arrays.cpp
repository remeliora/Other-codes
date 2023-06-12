#include <iostream>
#include <cmath>
#include "Arrays.h"

void Arrays::WriteSize() {
    std::cout << "Введите количество элементов в массиве " << std::endl;
    std::cin >> size1;
}

void Arrays::WriteElems () {
    for (int i = 0; i < size1; i++) {
        std::cout << "mas[ " << i << " ] = ";
        std::cin >> arr[i];
    }
}

void Arrays::Transform () {
    for (int i = 0; i < size1-1; i += 2) {
        arr[i] = arr[i] + arr[i + 1];  
    } 
}

void Arrays::PrintElems () {
    for (int i = 0; i < size1; i++)
        std::cout << arr[i] << " ";
}