#include <fmt/core.h>
#include <fmt/chrono.h>
#include <iostream>
#include "StringFMT.h"
#include <chrono>

using namespace std::chrono;
std::string StringFMT::printDate() {
    std::time_t t = std::time(nullptr);
    return fmt::format("{:%Y-%m-%d;%H-%M}-{:%S}", fmt::localtime(t), time_point_cast<milliseconds>(system_clock::now()).time_since_epoch());
}
std::string StringFMT::printCode() {
    srand(time(0));
    std::string codeOutput;
    for (int i = 0; i < 8; i++)
    {
        int num = rand() % 10;
        codeOutput += fmt::format("{}", num);
    }
    return codeOutput;
}
std::string StringFMT::printName() {
    return fmt::format("{}", m_name);
}


std::string StringFMT::buildString() {
    int delimCount = 5;
    m_size = printDate().size() + printName().size() + printCode().size() + delimCount;
    std::string noChecksum = fmt::format("{:02}\u0001{}\u0001{}\u0001{}\u0001{}\u0001", m_number, printDate(), m_size, printName(), printCode());

    uint16_t sum = 0;
    for (int i: noChecksum) {
        sum += i;
    }
    int checksum = sum % 256;

    return fmt::format("{}{}", noChecksum, checksum);
}

void StringFMT::printString() {
    std::cout << buildString();
}