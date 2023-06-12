#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {

    system("chcp 65001");
    system("cls");

    int NumOfArrElem, LenOfWord;
    string buffer, send, slovo, reserv, reserv_null;;
    vector <string> str;
    vector <string> str_copy;

    // Задание 1. Ограничения (размер массива - 100 слов, размер слов - 100 символов)
    cout << "Введите количество элементов массива: ";

    cin >> NumOfArrElem;

    if (NumOfArrElem > 100) {
        cout << "Введёное число больше, чем размер массива!";
        return 0;
    }

    for (int i = 0; i < NumOfArrElem; i++) {
        cout << "mas[ " << i << " ] = ";
        cin >> buffer;
        if (buffer.size() > 100) {
            cout << "Введённое количество символов в слове больше нормы!";
            return 0;
        }
        
        if (buffer.size() > 0) {
            // Добавление элемента в конец вектора
            str.push_back(buffer);
        }
    }

    cout << endl << "Вывод массива слов:" << endl;

    for (int i = 0; i < NumOfArrElem; i++) {
        cout << str[i] << " ";
    }

    // Задание 2. Инверсия
    cout << endl << endl << "Инверсия: " << endl;

    for (vector<string>::size_type i = str.size(); i != 0; ) {
        cout << str[--i] << ", ";
    }

    // Задание 3. Перестановка чётных и нечётных слов
    cout << endl << endl << "Перестановка чётных и нечётных слов: " << endl;

    for (int i = 0; i < NumOfArrElem - 1;) {
        send = str[i];
        str[i] = str[i + 1];
        str[i + 1] = send;
        i = i + 2;
    }
    
    for (int i = 0; i < NumOfArrElem; i++) {
        cout << str[i] << " ";
    }

    // Задание 4. Обрезание слов до определённой длины
    cout << endl << endl << "Введите число для обрезки слов: ";

    cin >> LenOfWord;

    cout << endl;

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
    
    cout << "Изначальный массив: " << endl;

    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    
    cout << endl << endl << "Преобразованный массив: " << endl;

    for (int i = 0; i < str_copy.size(); i++) {
        cout << str_copy[i] << " ";
    }
}