#include <iostream>
#include <string>

int main() {
    system("chcp 65001");
    system("cls");

    char n[3];
    std::string str;

    std::cout << "Введите элементы массива: " << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "mas[ " << i << " ] = ";
        std::cin >> n[i];
    }
    
    for (int i = 0; i < 3; i++) {
        std::cout << n[i] << " ";
    }
    
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        str += n[i];
    }
    
    for (int i = 0; i < 3; i++) {
        std::cout << str[i] << " ";
    }
    
    
}