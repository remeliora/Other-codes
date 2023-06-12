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

    int lenth = 0, num_of_col = 0, lenofkey = 0;
    char input[100], result[100];

    std::string result1;
    int key[6] = {6, 5, 3, 1, 2, 4};

    // Ввод изначального текста:
    cout << "Введите изначальный текст: " << endl;
    cin.getline(input, 255);

    lenth = strlen(input);  //подсчёт количества символов

    // Проверка ввода:
    cout << "Длина ввода: " << lenth << endl;
    cout << "Вы ввели: " << endl;
    for (int i = 0; i < lenth; i++) {
        cout << input[i];
    }
    cout << endl;

    // Если длина ввода не кратна длине ключа, добавляем нужное количество пробелов:
    if (lenth % 6 != 0) {
        for (int i = 0; i < 6 - (lenth - 6*(lenth / 6)); i++) { //!!!!!!!!!!!!!!
            strcat(input, " "); //Функция strcat завершает результирующую строку символом NULL
        }
    }

    lenth = strlen(input);  //подсчёт количества символов

    cout << lenth << endl;

    num_of_col = lenth / 6;

    cout << num_of_col << endl;

    char cipher_table [6][num_of_col];

    lenofkey = sizeof(key) / sizeof(*key);

    cout << lenofkey << endl;

    for (int i = 0; i < lenofkey; i++) {
        for (int j = 0; j < num_of_col; j++) {
            cipher_table[key[i]][j] = input[i];
        }   
    }

}