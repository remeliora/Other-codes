//Аттракцион вмещает несколько человек общим весом не более М кг
//Вес каждого человека, стоящего в очереди, генерируется датчиком случайных чисел (от 50 до 100)
//Программа должна выводить веса желающих прокатиться, пока суммарный вес не достигнет М

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    system("chcp 65001");   // для отображения русского языка
    system("cls");

    int max_weight; // максимальный вес для аттракциона
    int* randomWeight = new int[max_weight]; // массив желающих прокатиться на аттракционе
    int sum; //сумма рандомного веса
    int count = 0; // счётчик человек

    std::cout << "Введите максимальный вес, который вмещает аттракцион: ";
    std::cin >> max_weight;

    if (max_weight < 50) {
        std::cout << "Введён некорректный вес!" << std::endl;
        return 0;
    }
    
    std::cout << " (кг)";
    std::cout << std::endl;

    srand(time(NULL));  // установка начала отсчёта для генерации неповторяющихся случайных чисел
    for (int i = 0; i < max_weight; i++) {
        randomWeight[i] = rand() % 50 + 50; // генерация случайного веса для каждого человека
                                            // в диапазоне от 50 до 100 кг
        sum += randomWeight[i];
        count++;
        if (sum > max_weight) {
            sum = sum - randomWeight[i];
            count--;
            break;
        }
    }

    std::cout << "Вес каждого человека: " << std::endl; //Вывод веса каждого человека желающего прокатиться
    std::cout << std::endl;
    for (int i = 0; i < count; i++ ) {
        std::cout << "Вес "  << i + 1 << "-го человека - " << randomWeight[i] << " (кг) " << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Суммарный вес всех человек на аттракционе " << sum << " (кг)";
}