#include <iostream>

int perebor(int safeCode) {
    for (int number = 0; number < 1000; number++) {
		if (number == safeCode) {
			std::cout << "Kод = " << safeCode << ": Потребовалось " << number << " испытаний." << std::endl;
			return 0;
		}
	}
}

int main() {	
	system("chcp 65001");
    system("cls");

	int safeCode; // переменная для ввода пароля

    std::cout << "Введите пароль: ";
    std::cin >> safeCode; // вводим пароль
 
	std::cout << "Откроем сейф методом перебора:" << std::endl;
    perebor(safeCode);

	return 0;
}