#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>  // Библиотека для считывания с файла
using namespace std;
const int n = 10;	//Максимальное количество вершин, столбцов и строк в матрице
struct town {       //Структура по заданию
	string city;	// Название города
	int number;		// Количество жителей
};

struct graf {		//Структура графа
	town node[n];	//Массив вершин
	int matrix[n][n];//Матрица смежности
	int last; //индекс последнего элемента в массиве маршин, последних столбца и строки в матрице смежности
}A;

bool create() {    //создание графа заданной конфигурации
	ifstream file("text.txt");
	if (!file) {
		cout << "Файл отсутствует.";
		return false;
	}
	file >> A.last;  //считывается индекс последнего элемента
	for (int i = 0; i <= A.last; i++) { // В массив вершин считывается название города и количество жителей 
		file >> A.node[i].city;
		file >> A.node[i].number;
	}
	for (int i = 0; i <= A.last; i++) { //Считывается матрица смежности
		for (int j = 0; j <= A.last; j++)
			file >> A.matrix[i][j];
	}
	file.close(); // Файл закрывается
	return true;  //Если файл считался возвращается тру
}
void add_ver() {   //добавление вершины в созданный граф
	if (A.last >= n - 1) { cout << "Город не добавлен. В списке городов нет места"; return; } // Если индекс последнего элемента больше или равен максимальному количеству элементов, выводится сообщение
	else {
		A.last++; // Увеличиваем индекс посленего элемента
		cin.ignore();
		cout << "Введите название города: ";
		cin >> A.node[A.last].city; //По этому индексу записываем название города в массив вершин
		for (int i = 0; i < A.last; i++) { //Проверка есть ли уже такой город в графе
			if (A.node[A.last].city == A.node[i].city) {
				cout << "Город с таким названием уже существует";
				A.last--; //Уменьшаем, потому что операция добавления прерывается, а до этого мы увеличивали индекс
				return;
			}
		}
		cout << "Введите количество жителей: ";
		cin >> A.node[A.last].number; //Записываем по этому индексу в массив вершин количество жителей
		cout << "Город добавлен.";
	}
}
void delet_ver() { //удаление вершины из созданного графа
	string deletv; //Для записи удаляемого города
	int d; //Для индекса удаляемого города
	bool del = false; //Для определения есть ли такой город в графе или нет
	cin.ignore();
	cout << "Введите название города, который желаете удалить: ";
	cin >> deletv;
	for (int i = 0; i <= A.last; i++) { //Проходимся по массиву вершин
		if (A.node[i].city == deletv) { //Если введенный удаляемый город совпадает с одним из массива вершин
			d = i; del = true; //Записываем его индекс и присваеваем тру
		}
	}
	if (!del) { cout << "Города с таким названием нет в сети."; return; } //Если del осталась фолс значит такого города нет
	for (int i = 0; i <= A.last; i++) { //удаляем столбец матрицы начиная с индекса удаляемого города
		for (int j = d; j <= A.last; j++)
			A.matrix[i][j] = A.matrix[i][j + 1];//Смещаем впереди стоящий столбец на место текущего
	}
	for (int i = d; i <= A.last; i++) { //удаляем строку матрицы начиная с индекса удаляемого города
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
	cout << "Город удален из сети.";
}
void delet_r() {   //удаление ребра из созданного графа
	string first, second; //для записи первого и второго города
	int f, s; //для сохранения индексов первого и второго города
	cin.ignore();
	cout << "Введите название первого города: ";
	cin >> first;
	bool found1 = false; //для определения нашли или нет
	for (int i = 0; i <= A.last; i++) { //проходимся по массиву вершин и ищем совпадение
		if (A.node[i].city == first) {
			f = i; found1 = true; //если нашли записываем индекс найденого и присваеваем тру
		}
	}
	if (!found1) { cout << "Города с таким названием нет в сети"; return; } //если found1 остался фолс значит совпадения не было, такого города нет
	cout << "Введите название второго города: "; //для второго города тоже самое что и для первого
	cin >> second;
	bool found2 = false;
	for (int i = 0; i <= A.last; i++) {
		if (A.node[i].city == second) {
			s = i; found2 = true;
		}
	}
	if (!found2) { cout << "Города с таким названием нет в сети"; return; }
	if (A.matrix[f][s] == 1) { //если такая дорога существует (обозначается единицей в матрице смежности)
		A.matrix[f][s] = A.matrix[s][f] = 0; //обнуляем, т.е удаляем (т.к граф неориентированный удаляем на симметричных местах матрицы)
		cout << "Дорога удалена.";
	}
	else { cout << "Данной дороги не существует"; } //иначе такой дороги и не существовало
}

void add_r() {     //добавление ребра в созданный граф
	string first, second;//для записи первого и второго города
	int f, s; //для сохранения индексов первого и второго города
	cin.ignore();
	cout << "Введите название первого города: "; 
	cin >> first;
	bool found1 = false;//для определения нашли или нет
	for (int i = 0; i <= A.last; i++) { //проходимся по массиву вершин и ищем совпадение
		if (A.node[i].city == first) {
			f = i; found1 = true; //если нашли записываем индекс найденого и присваеваем тру
		}
	}
	if (!found1) { cout << "Города с таким названием нет в сети"; return; } //если found1 остался фолс значит совпадения не было, такого города нет
	cout << "Введите название второго города: "; //для второго города тоже самое что и для первого
	cin >> second;
	bool found2 = false;
	for (int i = 0; i <= A.last; i++) {
		if (A.node[i].city == second) {
			s = i; found2 = true;
		}
	}
	if (!found2) { cout << "Города с таким названием нет в сети"; return; }
	if (A.matrix[f][s] == 0) {     //если дороги не было (обозначается нулем в матрице смежности)
		A.matrix[f][s] = A.matrix[s][f] = 1; // создаем эту дорогут (т.к. граф неориентироанный создаем на симметричных местах матрицы)
		cout << "Дорога добавлена.";
	}
	else cout << "Данная дорога уже существует"; //иначе эта дорога уже есть (зачем её добавлять второй раз?)
}

void look() {      //вывод на экран краткой информации (только название) о смежных вершинах для всех вершин графа
	for (int i = 0; i <= A.last; i++) {  //проходимся по массиву вершин,заодно и по строкам матрицы
		cout << "Город: " << A.node[i].city << endl; //выводим эту вершину
		int c = 0; //для подсчета количества соседей
		cout << "Соседние города: " << endl;
		for (int j = 0; j <= A.last; j++) { //проходимся по столбцам матрицы смежности
			if (A.matrix[i][j] == 1) { //если между городами есть дорога выводим этот город
				cout << A.node[j].city << endl;
				c++; //увеличиваем количество соседей
			}
		}
		if (c == 0) { cout << "отсутствуют." << endl; } //если количество соседей осталось равным 0, значит их нет, выводи сообщение
		cout << "----------" << endl;
	}
}

void neighbors() { //Сколько соседей есть у указанного города. Какой из этих городов имеет наименьшее количество жителей
	town cit; //Для записи города о кторои ищем информацию
	int imin, count_neighbors = 0;  //индекс минимального элемента и количество соседей
	bool neigh = false; //для определения нашли город или нет
	cin.ignore();
	cout << "Введите название города: ";
	cin >> cit.city;
	for (int i = 0; i <= A.last; i++) { //проходимся по массиву вершин
		if (A.node[i].city == cit.city) { //если нашли совпадение с введенным городом
			neigh = true;
			for (int j = 0; j <= A.last; j++) { //проходимся по матрице по столбцам в строке этого города
				if (A.matrix[i][j] == 1) { //если есть дорога увеличиваем количество соседей
					count_neighbors++;
					imin = j; //обозначаем найденный как минимальный элемент
				}
			}
			for (int m = 0; m <= A.last; m++) { //проходимся по столбцам снова
				if (A.matrix[i][m] == 1) {  //если дрога существует
					if (A.node[imin].number > A.node[m].number) imin = m; //свравниваем количество жителей если есть город в котором меньше, то записываем его индекс
				}
			}
		}
	}
	if (!neigh) { cout << "Города с таким названием нет в сети."; return; } //если neight остался фолс значит мы не нашли город
	if (count_neighbors == 0) { cout << "Соседних городов нет." << endl; return; } //если счетчик количества соседей остался равен 0, выводим сообщение
	cout << "Количество соседей : " << count_neighbors << endl; //иначе выводим количество соседей
	cout << "Город с наименьшим количеством жителей: " << A.node[imin].city; //и выводим город с наименьшим количеством жителей
}

int main() {
    system("chcp 65001");
    system("cls");
    
	A.last = -1; //Присваеваем индексу последнего элемента -1, т.к индексация начинается с 0 (т.е. вершин еще нет)
	for (int i = 0; i < n; i++) //заполняем матрицу нулями
		for (int j = 0; j < n; j++)
			A.matrix[i][j] = 0;
	if (create()){ //считываем с файла начальный граф и выводим меню
		while (true) {
			int option;
			cout << "\n---------------------------------\n";
			cout << "Введите номер опции: " << endl;
			cout << "1 - Добавить город в созданный граф" << endl;
			cout << "2 - Удалить город из созданного графа" << endl;
			cout << "3 - Удалить дорогу между городами" << endl;
			cout << "4 - Добавить дорогу между городами" << endl;
			cout << "5 - Краткая информация(только название) о соседних городах для всех городов сети" << endl;
			cout << "6 - Сколько соседей есть у указанного города? Какой из этих городов имеет наименьшее количество жителей?" << endl;
			cout << "0 - Выход" << endl;
			cin >> option; //считываем номер опции и проходим по свичу
			switch (option) {
			case 0: return 0;
			case 1:add_ver(); break;
			case 2: if (A.last == -1) cout << "Cеть городов пуста"; //если индекс последнего элемента равен -1 значит граф пуст
				  else delet_ver(); break;
			case 3:if (A.last == -1) cout << "Cеть городов пуста";
				  else delet_r(); break;
			case 4:if (A.last == -1) cout << "Cеть городов пуста";
				  else  add_r(); break;
			case 5: if (A.last == -1) cout << "Cеть городов пуста";
				  else  look(); break;
			case 6: if (A.last == -1)cout << "Cеть городов пуста";
				  else neighbors(); break;
			default: cout << "Должно быть вы ошиблись. Опции с данным номером не существует." << endl; break;
			}
		}
	}
	else return 0; //если файл не считался завершаем программу
}