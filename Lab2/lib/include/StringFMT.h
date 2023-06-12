#pragma once
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;
class StringFMT {
    private:
        std::string m_str;
        std::string m_name;
        int m_size;
        int m_number;

    public:
        StringFMT(std::string name, int number) : m_name(name), m_number(number) {}
        std::string printDate();
        std::string printName();
        std::string printCode();
        std::string printDelim();
        std::string buildString();
        void printString();
};