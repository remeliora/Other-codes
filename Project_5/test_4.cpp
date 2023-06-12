#include <iostream>
#include <string>

const int i = 5;        // количество записей в структуре Monster

struct Monster {                // структура монстров
    std::string TypeOfMonster;  // Раса монстра4
    std::string NameOfMonster;  // Имя монстра
    int HealthPoints;           // Очки здоровья монстра
} ListOfMonster[i];     // краткое название для ображения к структуре в коде

struct List {           // структура - указатель на структуру Monster
    Monster ListOfMonster[i];   // обращение к массиву - структуре Monster
    int LastMonster = -1;       // индекс последнего элемента структуры
} Send;                 // краткое название для ображения к структуре в коде

Monster Add_Monster() {     // функция добавления монстра в список
    Send.LastMonster += 1;  // начинаем запись с нулевого элемента структуры
    std::cout << "Введите расу монстра: ";
    std::cin >> ListOfMonster[Send.LastMonster].TypeOfMonster; // обращение для записи в структуру расы монстра
    std::cout << std::endl;
    std::cout << "Введите имя монстра: ";
    std::cin >> ListOfMonster[Send.LastMonster].NameOfMonster; // обращение для записи в структуру имени монстра
    std::cout << std::endl;
    std::cout << "Введите кол-во очков здоровья монстра: ";
    std::cin >> ListOfMonster[Send.LastMonster].HealthPoints; // обращение для записи в структуру очков здоровья монстра
    std::cout << std::endl;
    return ListOfMonster[Send.LastMonster];
}

void Print_Full_List(int last_elem) {       // функция вывода всего списка монстров со всеми характеристиками
    if (last_elem != -1){   //если список не нулевой, то...
        std::cout << "============= Список монстров =============" << std::endl;
        int k = 0;
        while (last_elem >= 0) {    // проход по всему списку
            std::cout << std::endl;
            std::cout << "Раса: " << ListOfMonster[k].TypeOfMonster << std::endl;
            std::cout << "Имя: " << ListOfMonster[k].NameOfMonster << std::endl;
            std::cout << "Очки здоровья: " << ListOfMonster[k].HealthPoints << std::endl;
            last_elem -= 1;
            k++;
        }
    }
    else {
        std::cout << "Список пуст..." << std::endl;
    }
}

void Print_Monster_Inf() {  //функция вывода характеристики конкретного монстра
    if (Send.LastMonster != -1) {   
        std::string temp;   // строка для записи имени монстра, которого хотим вывести
        std::cout << "Введите полное имя монстра: ";
        std::cin >> temp;
        std::cout << std::endl;
        for (int k = 0; k <= Send.LastMonster; k++) {   // цикл для прохода по всей структуре
            if (temp == ListOfMonster[k].NameOfMonster) {   //если то что мы ввели сходится с каким-то элементом, то...
                std::cout << "Раса: " << ListOfMonster[k].TypeOfMonster << std::endl;
                std::cout << "Имя: " << ListOfMonster[k].NameOfMonster << std::endl;
                std::cout << "Очки здоровья: " << ListOfMonster[k].HealthPoints << std::endl;
            }
        }
    }
    else {
        std::cout << "Список пуст..." << std::endl;
    }
}

void Print_Monster_Names(int last_elem) {   // функция вывода списка монстром по имени 
    if (last_elem != -1){
        std::cout << "============= Список монстров по имени =============" << std::endl;
        int k = 0;
        while (last_elem >= 0) {
            std::cout << std::endl;
            std::cout << "Имя: " << ListOfMonster[k].NameOfMonster << std::endl;
            last_elem -= 1;
            k++;
        }
    }
    else {
        std::cout << "Список пуст..." << std::endl;
    }
}

int main() {
    system("chcp 65001");   // для отображения русского языка
    system("cls");

	int mark = 1, label; // номер операции
	Monster* list_head = NULL; //список пустой
	while (mark) {
		std::cout << "Данная программа создаёт список монстров по имени, расе и очкам здоровья" << std::endl
                  << "           Введите номер операции, которую хотите выполнить" << std::endl << std::endl;
		std::cout << "1. Добавить монстра в список" << std::endl;
		std::cout << "2. Вывести весь список монстров" << std::endl;
		std::cout << "3. Найти монстра по имени и вывести его характеристики" << std::endl;
		std::cout << "4. Вывести список монстров по имени" << std::endl;
		std::cout << "# операции - "; 
        std::cin >> label;  //вводим номер функции (операции), которая нам необходима
		std::cout << std::endl << std::endl;
		switch (label) {
		case 0: 
			mark = 0;
			break;
		case 1:
			Add_Monster();
			break;
		case 2:
			Print_Full_List(Send.LastMonster);
			break;
		case 3:
			Print_Monster_Inf();
			break;
		case 4:
			Print_Monster_Names(Send.LastMonster);
			break;
		default:
			std::cout << "Введенный номер операции неверный, проверьте значение еще раз" << std::endl;
			break;
		}
		system("pause");
		system("CLS");  // очистка терминала
	}

	return 0;
}