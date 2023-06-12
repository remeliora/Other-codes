#include <iostream>
#include <cmath>
#include "Arrays.h"

void Arrays::WriteSize() {
    std::cout << "Введите количество элементов в массиве " << std::endl;
    std::cin >> size;
}

void Arrays::WriteElems () {
    for (int i = 0; i < size; i++) {
        std::cout << "mas[ " << i << " ] = ";
        std::cin >> arr[i];
    }
}

void Arrays::Transform () {
    // for (int i = 0; i < size-1; i += 2) {
    //     arr[i] = arr[i] + arr[i + 1];
    // } 
    for (int i = 0; i < size; i++) {
        mass[i] = arr[i];
    }
    
}

void Arrays::PrintElems () {
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << mass[i] << " ";
    }
}