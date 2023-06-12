#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "OPI_1.h"

void Array::Write_NumOfArrElem() {
    std::cin >> NumOfArrElem;
}

void Array::Write_LenOfWord() {
    std::cin >> LenOfWord;
}

void Array::Exercise_1() {
    if (NumOfArrElem > 100) {
        std::cout << "Введёное число больше, чем размер массива!";
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < NumOfArrElem; i++) {
        std::cout << "mas[ " << i << " ] = ";
        std::cin >> buffer;
        if (buffer.size() > 100) {
            std::cout << "Введённое количество символов в слове больше нормы!";
            exit(EXIT_SUCCESS);
        }
        
        if (buffer.size() > 0) {
            // Добавление элемента в конец вектора
            str.push_back(buffer);
        }
    }
}

void Array::Exercise_2() {
    std::cout << std::endl << std::endl << "Инверсия: " << std::endl;

    for (std::vector<std::string>::size_type i = str.size(); i != 0; ) {
        std::cout << str[--i] << ", ";
    }
}

void Array::Exercise_3() {
    std::cout << std::endl << std::endl << "Перестановка чётных и нечётных слов: " << std::endl;

    for (int i = 0; i < NumOfArrElem - 1;) {
        send = str[i];
        str[i] = str[i + 1];
        str[i + 1] = send;
        i = i + 2;
    }
}

void Array::Exercise_4() {
    std::cout << std::endl;

    for (int i = 0; i < NumOfArrElem; i++) {
        str_copy.push_back(str[i]);
    }

    for (int i = 0; i < NumOfArrElem; i++) {
        slovo = str_copy[i];
        // cout << slovo << endl;
        // for (int i = 0; i < slovo.size(); i++) {
        //     cout << slovo[i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < LenOfWord; i++) {
            reserv += slovo[i];
        }
        // for (int i = 0; i < reserv.size(); i++) {
        //     cout << reserv[i] << " ";
        // }
        // cout << endl;
        str_copy[i] = reserv;
        reserv = reserv_null;
        // cout << reserv << ", " << reserv_null << endl;
    }
}

void Array::PrintOriginalArray() {
    for (int i = 0; i < NumOfArrElem; i++) {
        std::cout << str[i] << " ";
    }
}

void Array::PrintConvertedArray() {
    for (int i = 0; i < str_copy.size(); i++) {
        std::cout << str_copy[i] << " ";
    }
}