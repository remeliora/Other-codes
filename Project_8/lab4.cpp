﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream> // Библиотека для считывания с файла
using namespace std;

const int n = 10;	//Максимальное количество вершин, столбцов и строк в матрице

struct equipment {       //Структура по заданию
	string name;	// Название оборудования
	string ip;		// IP-адрес оборудования
};

struct graf {		//Структура графа
	equipment node[n];	//Массив вершин
	int matrix[n][n];//Матрица смежности
	int last; //индекс последнего элемента в массиве маршин, последни столбца и строки в матрице смежности
}A;

bool create() {    //создание графа заданной конфигурации
	ifstream file;
	file.open("text.txt");
	if (!file) {
		cout << "Файл отсутствует.";
		return false;
	}
	file >> A.last;  //считывается индекс последнего элемента
	for (int i = 0; i <= A.last; i++) { // В массив вершин считывается название оборудования и IP-адрес оборудования 
		file >> A.node[i].name;
		file >> A.node[i].ip;
	}
	for (int i = 0; i <= A.last; i++) { //Считывается матрица смежности
		for (int j = 0; j <= A.last; j++)
			file >> A.matrix[i][j];
	}
	file.close(); // Файл закрывается
	return true;  //Если файл считался возвращается тру
}
void add_ver() {   //добавление вершины в созданный граф
	if (A.last >= n - 1) { cout << "Оборудование не добавлено. В списке оборудования нет места"; return; } // Если индекс последнего элемента больше 
	//или равен максимальному количеству элементов, выводится сообщение
	else {
		A.last++; // Увеличиваем индекс посленего элемента
		cin.ignore();
		cout << "Введите название оборудования: ";
		cin >> A.node[A.last].name; //По этому индексу записываем название оборудования в массив вершин
		for (int i = 0; i < A.last; i++) { //Проверка есть ли уже такое оборудование в графе
			if (A.node[A.last].name == A.node[i].name) {
				cout << "Оборудование с таким названием уже существует";
				A.last--; //Уменьшаем, потому что операция добавления прерывается, а до этого мы увеличивали индекс
				return;
			}
		}
		cout << "Введите IP-адрес оборудования: ";
		cin >> A.node[A.last].ip; //Записываем по этому индексу в массив вершин IP-адрес оборудования
		cout << "Оборудование добавлено.";
	}
}
void delet_ver() { //удаление вершины из созданного графа
	string deletv; //Для записи удаляемого оборудования
	int d; //Для индекса удаляемого оборудования
	bool del = false; //Для определения есть ли такое оборудование в графе или нет
	cin.ignore();
	cout << "Введите название оборудования, который желаете удалить: ";
	cin >> deletv;
	for (int i = 0; i <= A.last; i++) { //Проходимся по массиву вершин
		if (A.node[i].name == deletv) { //Если введенный удаляемое оборудование совпадает с одним из массива вершин
			d = i; del = true; //Записываем его индекс и присваеваем тру
		}
	}
	if (!del) { cout << "Оборудования с таким названием нет в сети."; return; } //Если del осталась фолс значит такого оборудования нет
	for (int i = 0; i <= A.last; i++) { //удаляем столбец матрицы начиная с индекса удаляемого оборудования
		for (int j = d; j <= A.last; j++)
			A.matrix[i][j] = A.matrix[i][j + 1];//Смещаем впереди стоящий столбец на место текущего
	}
	for (int i = d; i <= A.last; i++) { //удаляем строку матрицы начиная с индекса удаляемого оборудования
		for (int j = 0; j <= A.last; j++)
			A.matrix[i][j] = A.matrix[i + 1][j]; //смещаем впереди стоящую сточку на место текущей
	}
	for (int i = d; i <= A.last; i++) { //удаляем вершину
		A.node[i] = A.node[i + 1];// так же смещаем

	}
	for (int i = A.last; i < n; i++) { //заполняем освободившееся нулями
		for (int j = A.last; j < n; j++)
			A.matrix[i][j] = 0;
	}
	A.last--; //уменьшаем индекс
	cout << "Оборудование удалено из сети.";
}
void delet_r() {   //удаление ребра из созданного графа
	string first, second; //для записи первого и второго оборудования
	int f, s; //для сохранения индексов первого и второго оборудования
	cin.ignore();
	cout << "Введите название первого оборудования: ";
	cin >> first;
	bool found1 = false; //для определения нашли или нет
	for (int i = 0; i <= A.last; i++) { //проходимся по массиву вершин и ищем совпадение
		if (A.node[i].name == first) {
			f = i; found1 = true; //если нашли записываем индекс найденого и присваеваем тру
		}
	}
	if (!found1) { cout << "Оборудования с таким названием нет в сети"; return; } //если found1 остался фолс значит совпадения не было, такого оборудования нет
	cout << "Введите название второго оборудования: "; //для второго оборудования тоже самое что и для первого
	cin >> second;
	bool found2 = false;
	for (int i = 0; i <= A.last; i++) {
		if (A.node[i].name == second) {
			s = i; found2 = true;
		}
	}
	if (!found2) { cout << "Оборудования с таким названием нет в сети"; return; }
	if (A.matrix[f][s] == 1) { //если такая дорога существует (обозначается единицей в матрице смежности)
		A.matrix[f][s] = A.matrix[s][f] = 0; //обнуляем, т.е удаляем (т.к граф неориентированный удаляем на симметричных местах матрицы)
		cout << "Соединение удалено.";
	}
	else { cout << "Данного соединения не существует"; } //иначе такой дороги и не существовало
}

void add_r() {     //добавление ребра в созданный граф
	string first, second;//для записи первого и второго оборудования
	int f, s; //для сохранения индексов первого и второго оборудования
	cin.ignore();
	cout << "Введите название первого оборудования: ";
	cin >> first;
	bool found1 = false;//для определения нашли или нет
	for (int i = 0; i <= A.last; i++) { //проходимся по массиву вершин и ищем совпадение
		if (A.node[i].name == first) {
			f = i; found1 = true; //если нашли записываем индекс найденого и присваеваем тру
		}
	}
	if (!found1) { cout << "Оборудования с таким названием нет в сети"; return; } //если found1 остался фолс значит совпадения не было, такого оборудования нет
	cout << "Введите название второго оборудования: "; //для второго оборудования тоже самое что и для первого
	cin >> second;
	bool found2 = false;
	for (int i = 0; i <= A.last; i++) {
		if (A.node[i].name == second) {
			s = i; found2 = true;
		}
	}
	if (!found2) { cout << "Оборудования с таким названием нет в сети"; return; }
	if (A.matrix[f][s] == 0) {     //если дороги не было (обозначается нулем в матрице смежности)
		A.matrix[f][s] = A.matrix[s][f] = 1; // создаем эту дорогут (т.к. граф неориентироанный создаем на симметричных местах матрицы)
		cout << "Соединение добавлено.";
	}
	else cout << "Данное соединение уже существует"; //иначе эта дорога уже есть (зачем её добавлять второй раз?)
}

void look() {      //вывод на экран краткой информации (только название) о смежных вершинах для всех вершин графа
	for (int i = 0; i <= A.last; i++) {  //проходимся по массиву вершин,заодно и по строкам матрицы
		cout << "Оборудование: " << A.node[i].name << endl; //выводим эту вершину
		int c = 0; //для подсчета количества соседей
		cout << "Соседние оборудования: " << endl;
		for (int j = 0; j <= A.last; j++) { //проходимся по столбцам матрицы смежности
			if (A.matrix[i][j] == 1) { //если между оборудованиями есть дорога выводим это оборудование
				cout << A.node[j].name << endl;
				c++; //увеличиваем количество соседей
			}
		}
		if (c == 0) { cout << "отсутствуют." << endl; } //если количество соседей осталось равным 0, значит их нет, выводи сообщение
		cout << "----------" << endl;
	}
}

//==============================================================================================================
//Из каких узлов сети доступен компьютер с указанным IP-адресом
//==============================================================================================================
void task() {
	equipment p; // Для указания ip которое ищем
	int c = 0; //Для определения существуют ли узлы
	bool found = false; //для определения существует ли такой IP-адрес
	cout << "Введите IP-адрес: ";
	cin >> p.ip;
	for (int i = 0; i <= A.last; i++) {  
		if (A.node[i].ip == p.ip) { //Если в списке вершин есть данный IP-адрес
			found = true;
			cout << "IP-адрес доступен из: " << endl;
			for (int j = 0; j <= A.last; j++) { //Проходимся по столбцам матрицы и ищем соединения 
				if (A.matrix[i][j] == 1) {
					c++;
					cout << "Узла " << A.node[j].name << " c ip-адресом " << A.node[j].ip << endl;
				}
			}
		}
	}
	if (!found) { cout << "Данного IP-адреса не существует"; return; }
	if (c == 0) { cout << "Узлов, из которых данный IP-адрес доступен, не существует "; return; }
}

int main() {
	system("chcp 65001");
    system("cls");

	A.last = -1; //Присваеваем индексу последнего элемента -1, т.к индексация начинается с 0 (т.е. вершин еще нет)
	for (int i = 0; i < n; i++) //заполняем матрицу нулями
		for (int j = 0; j < n; j++)
			A.matrix[i][j] = 0;
	if (create()) { //считываем с файла начальный граф и выводим меню
		while (true) {
			int option;
			cout << "\n---------------------------------\n";
			cout << "Введите номер опции: " << endl;
			cout << "1 - Добавить оборудование в созданный граф" << endl;
			cout << "2 - Удалить оборудование из созданного графа" << endl;
			cout << "3 - Удалить соединение между оборудованиями" << endl;
			cout << "4 - Добавить соединение между оборудованиями" << endl;
			cout << "5 - Краткая информация(только название) о соседних приборах для всех оборудований сети" << endl;
			cout << "6 - Из каких узлов сети доступен компьютер с указанным IP-адресом" << endl;
			cout << "0 - Выход" << endl;
			cin >> option; //считываем номер опции и проходим по свичу
			switch (option) {
			case 0: return 0;
			case 1:add_ver(); break;
			case 2: if (A.last == -1) cout << "Cеть оборудований пуста"; //если индекс последнего элемента равен -1 значит граф пуст
				  else delet_ver(); break;
			case 3:if (A.last == -1) cout << "Cеть оборудований пуста";
				  else delet_r(); break;
			case 4:if (A.last == -1) cout << "Cеть оборудований пуста";
				  else  add_r(); break;
			case 5: if (A.last == -1) cout << "Cеть оборудований пуста";
				  else  look(); break;
			case 6: if (A.last == -1)cout << "Cеть оборудований пуста";
					  else task(); break;
			default: cout << "Должно быть вы ошиблись. Опции с данным номером не существует." << endl; break;
			}
		}
	}
	else return 0; //если файл не считался завершаем программу
}