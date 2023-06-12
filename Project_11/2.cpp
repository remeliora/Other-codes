#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int i, j, n=0 , lengthk2;
    const int lengthk1 = 6;
    int k1[lengthk1] = { 6,5,3,1,2,4 };
    char* str = new char[255];
    cout << "Введите зашифрованный текст:\n";
    cin.getline(str, 255);
    cout << "Введите размер ключа:\n";
    cin >> lengthk2;
    int* k2 = new int[lengthk2];
    cout << "Введите ключ 2:\n";
    for (j = 0; j < lengthk2; j++) {
        cin >> k2[j];
    }
    char** arr;
    arr = new char* [lengthk1];
    for (i = 0; i < lengthk1; i++) {
        arr[i] = new char[lengthk2];
    }
   

    // заносим зашифрованный текст по столбцам в матрицу
    
    for (j = 0; j < lengthk2; j++) {
        for (i = 0; i < lengthk1; i++) {
                arr[i][k2[j]-1] = str[n]; n++;
        }      
    }
    // выводим текст по строкам в соответсвии с ключем 1
    cout << "Дешифрованный текст:\n";
    for (i=0; i < lengthk1; i++) {
        for (j = 0; j < lengthk2; j++) {
            cout << arr[k1[i]-1][j];
        }
    }

    delete[] str;
    delete[] k2;
    for (i = 0; i < lengthk1; i++) { delete[] arr[i]; }
    delete[] arr;
}
