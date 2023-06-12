#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

struct Data {
    std::string first;
    std::string second;
};

int main() {
    system("chcp 65001");
    system("cls");

    std::ifstream file("table.csv");

    if (!file.is_open()) {
        std::cerr << "Ошибка: не удается открыть файл" << std::endl;
        return 1;
    }

    std::map<std::string, std::vector<Data>> data;
    std::string line;

    std::getline(file, line);
    while (std::getline(file, line)) {

        std::string::size_type pos1 = line.find(';');
        std::string::size_type pos2 = line.find(';', pos1 + 1);

        std::string col1 = line.substr(0, pos1);
        std::string col2 = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string col3 = line.substr(pos2 + 1);

        Data value{ col2, col3 };
        data[col1].push_back(value);
    }

    file.close();

    for (const auto& kv : data) {
        std::cout << std::endl << "N-max = " << kv.first << ": (кол-во элементов = " << kv.second.size() << ") " << std::endl << std::endl;

        for (const Data& value : kv.second) {
            std::cout << value.first << " ";
            std::cout << value.second << std::endl;
        }
    }

    return 0;
}
