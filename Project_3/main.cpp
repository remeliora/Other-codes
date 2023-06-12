//Аттракцион вмещает несколько человек общим весом не более М кг
//Вес каждого человека, стоящего в очереди, генерируется датчиком случайных чисел ( от 50 до 100)
//Программа должна выводить веса желающих прокатиться, пока суммарный вес не достигнет М

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    system("chcp 65001");   // для отображения русского языка
    system("cls");

    int size = 0; // размер массива кол-ва человек
    int* randomWeight = new int[size]; // динамический массив желающих прокатиться на аттракционе
    int max_weight; // максимальный вес для аттракциона
    int sum; //сумма рандомного веса
    int count = 0; // счётчик человек
    // int min_gran = 50, max_gran = 100;


    std::cout << "Введите максимальный вес, который вмещает аттракцион: ";
    std::cin >> max_weight;
    std::cout << std::endl;

    std::cout << "Введите количество человек, желающих прокатиться на аттракционе: ";
    std::cin >> size;
    std::cout << std::endl;
    
    srand(time(NULL));  // установка начала отсчёта для генерации неповторяющихся случайных чисел
    for (int i = 0; i < size; i++) {
        randomWeight[i] = rand() % 50 + 50; // генерация случайного веса для каждого человека
                                            // в диапазоне от 50 до 100 кг
    }

    std::cout << "Вес каждого человека: " << std::endl; //Вывод веса каждого человека желающего прокатиться
    std::cout << std::endl;
    for (int i = 0; i < size; i++ ) {
        std::cout << "Вес "  << i + 1 << "-го человека - " << randomWeight[i] << " (кг) " << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Люди заходят на аттракцион по одному, для проверки на максимальный вес..." << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        sum += randomWeight[i];
        count++;
        std::cout << sum << " (кг) - ";
        if (sum <= max_weight) {
            std::cout << "Текущая масса соответствует стандартной норме." << std::endl;
        }
        else if (sum > max_weight) {
            std::cout << "Текущая масса превысила норму!" << std::endl;
            break;
        }
    }
    
    std::cout << std::endl;
    if (count == size && sum <= max_weight) {
        std::cout << "Аттракцион вместил " << count << " из " << size << " человек." << std::endl;
        std::cout << "Желаем всем приятного времяпрепровождения!" << std::endl;
        std::cout << std::endl;
    }
    else {
        std::cout << "Превышена максимально допустимая норма" << std::endl;
        std::cout << "Аттракцион смог вместить " << count - 1 << " из " << size << " человек." << std::endl;
        std::cout << std::endl;
    }
    return 0;
}