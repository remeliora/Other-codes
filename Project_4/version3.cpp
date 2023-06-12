//осуществить поразрядную сортировку LSD методом (строки фиксированной длины
//с указанием колическтва символов по которым производится сортировка)
//Двигаемся от младших разрядов к старшим и на каждой итерации распределяем элементы массива в зависимости от того, какая цифра содержится в разряде.
//После очередного распределения мы возвращаем элементы в основной массив в том порядке, в котором элементы попали в классы при очередном перераспределении.
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int n; // количество строк
int	k; // количество символов по которым проходит сортировка

int main() {
	system("chcp 65001");
    system("cls");

	ifstream file("text.txt");
	if (!file) {
		cout << "Файл отсутствует.";
		return 0;
	}
	else {
		file >> n;
		file >> k;
		string* s = new string[n];
		for (int i = 0; i < n; i++) {
			file >> s[i];
		}
		file.close();

		// for (int i = 0; i < n; i++) {
		// 	if (s[0].size() != s[i].size()) {
		// 		cout << "Присутствуют строки разной длины.";
		// 		return 0;
		// 	}
		// }

		if (k > s[0].size() || k < 0) {
			cout << "Указанное количество символов для сортировки, больше длины строки";
			return 0;
		}

		string str = "abcdefghijklmnopqrstuvwxyz";
		int size = str.size();
		int p = 1;
		ofstream fout("output.txt");

		fout << "Initial array: " << endl; // вывод изначального массива
		for (int i = 0; i < n; i++) {
			fout << s[i] << " ";
		}
		fout << endl;

		string** bucket = new string * [size]; // массив корзин
		for (int i = 0; i < size; i++) {
			bucket[i] = new string[n];
		}
		int* c = new int[size]; //счетчик
		for (k; k > 0; k--) { //цикл по количеству сортируемых элементов

			for (int i = 0; i < size; i++) {
				c[i] = 0;
			}

			for (int j = 0; j < n; j++) {   //проход по массиву строк
				for (int i = 0; i < size; i++) {       //проход по алфавиту
					if (str[i] == s[j][k-1]) {
						bucket[i][c[i]] = s[j];     //записываем в соответствующую строку
						c[i]++;
					}
				}
			}
			//считывание в массив из корзин с выводом в файл
			int ind = 0;
			fout << "Phase " << p << endl;
			for (int i = 0; i < size; i++) {
				fout << "Bucket " << str[i] << " : ";
				if (c[i] == 0) { fout << "empty"; }
				else {
					for (int j = 0; j < c[i]; j++) {
						fout << bucket[i][j] << " ";
						s[ind] = bucket[i][j];
						ind++;
					}
				}
				fout << endl;
			}
			p++;

		}
		for (int i = 0; i < size; i++) { delete[] bucket[i]; } //освобождаем память
		delete[] bucket;
		delete[] c;
		fout << "Sorted array: " << endl; //выводим отсортированный массив
		for (int i = 0; i < n; i++) {
			fout << s[i] << " ";
		}
		fout.close();
		cout << "Cортировка завершена"; 
		return 0;
	}
}
