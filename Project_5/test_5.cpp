#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main() {
    system("chcp 65001");   // для отображения русского языка
    system("cls");

	int n = 164, m = 3;       // Создание переменных отвечающих за размер вектора
    // std::cin >> n >> m;  // Ввод размеров вектора
	std::vector<std::vector<double>> matrix (n, std::vector<double> (m, 0));

	std::ifstream file("table.csv");
	if (!file) {
		std::cout << "Файл отсутствует.";
		return false;
	}
	for (int i = 0; i != n; ++i) {
   		for (int j = 0; j != matrix[i].size(); ++j) {
      		file >> matrix[i][j];
   		}
	}

	for (int i = 0; i < n; i++) {	// Цикл, который идёт по строкам
        for (int j = 0; j < m; j++)	// Цикл, который идёт по элементам
            std::cout << matrix[i][j] << ' ';	// Вывод элементов i строки вектора
        std::cout << std::endl;
    }
}