//сделать программу для универсального ключа
//ввод ключа в память
#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    // Корректное отображение русского языка
    system("chcp 65001");
    system("cls");

    int LenOfInput = 0; //количество символов в строке
    int iter = 0;   //счётчик элементов строки с исходным текстом

    const int LenghtOfKey1 = 6; //размер ключа K1
    int key_1[LenghtOfKey1] = {6, 5, 3, 1, 2, 4};   //ключ k1

    int LenghtOfKey2 = 0;   //размер ключа k2
    int* key_2 = new int[LenghtOfKey2]; //динамический ключ k2

    char* input = new char[255];    //динамический массив для ввода изначального текста

    // Ввод изначального текста
    cout << "Введите изначальный текст: " << endl;
    cin.getline(input, 255);

    LenOfInput = strlen(input); //подсчёт количества символов

    //Проверка ввода
    cout << "Длина ввода: " << LenOfInput << endl;
    cout << "Вы ввели: " << endl;
    for (int i = 0; i < LenOfInput; i++) {
        cout << input[i];
    }
    cout << endl;

    //Если длина ввода не кратна длине ключа, 
    //добавляем нужное количество пробелов:
    if (LenOfInput % LenghtOfKey1 != 0) {
        for (int i = 0; i < LenghtOfKey1 - (LenOfInput - LenghtOfKey1*(LenOfInput / LenghtOfKey1)); i++) {  //проверка кратности на длину k1
            strcat(input, " "); //Функция strcat добавляет пробел в конец строки
                                //(завершает результирующую строку символом NULL)
        }
    }

    LenOfInput = strlen(input);  //подсчёт количества символов

    //Проверка длины после добавления пробелов
    cout << "Новая длина строки: " << LenOfInput << endl;
    cout << "Новый ввод с пробелами: " << endl;
    for (int i = 0; i < LenOfInput; i++) {
        cout << input[i];
    }
    cout << endl;

    LenghtOfKey2 = LenOfInput / LenghtOfKey1;   //расчитываем размер ключа K2

    cout << "Введите ключ K2 через пробел (размер ключа равен " << LenghtOfKey2 << "):" << endl;

    for (int i = 0; i < LenghtOfKey2; i++) {    //ввод ключа K2 
        cin >> key_2[i];
    }
    
    //Проверка введённых значений в ключ K2
    cout << "Ключ 2 = { ";
    for (int i = 0; i < LenghtOfKey2; i++) {
        cout << key_2[i] << " ";
    }
    cout << "}" << endl;

    char** CipherTable;
    CipherTable = new char*[LenghtOfKey1];  //динамический массив для шифр-таблицы
    for (int i = 0; i < LenghtOfKey1; i++) {
        CipherTable[i] = new char[LenghtOfKey2];
    }

    //занесение исходного текста по строкам в матрицу
    for (int i = 0; i < LenghtOfKey1; i++) {
        for (int j = 0; j < LenghtOfKey2; j++) {
            CipherTable[key_1[i]-1][j] = input[iter];
            iter++;
        }
    }
    cout << endl;
    
    //вывод шифр таблицы
    for (int i = 0; i < LenghtOfKey1; i++) {
        for (int j = 0; j < LenghtOfKey2; j++) {
            cout << CipherTable[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //вывод текста по столбцам в соотвествии с ключом 2
    cout << "Шифрованный текст" << endl;
    for (int j = 0; j < LenghtOfKey2; j++) {
        for (int i = 0; i < LenghtOfKey1; i++) {
            cout << CipherTable[i][key_2[j]-1];
        }
    }
    
    //освобождение ранее занятой памяти
    delete[] input;
    delete[] key_2;
    for (int i = 0; i < LenghtOfKey1; i++) {
        delete[] CipherTable[i];
    }
    delete[] CipherTable;

    return 0;
}