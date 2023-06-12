#pragma once
#include <string>
#include <vector>

class Array {
    private:
        int NumOfArrElem, LenOfWord;
        std::string buffer, send, slovo, reserv, reserv_null;;
        std::vector <std::string> str;
        std::vector <std::string> str_copy;
    public:
        Array(int NumOfArrElem = 0, int LenOfWord = 0): NumOfArrElem(NumOfArrElem), LenOfWord(LenOfWord) {}

        Array(std::string buffer, std::string send, std::string slovo, std::string reserv, std::string reserv_null) {
            this->buffer;
            this->send;
            this->slovo;
            this->reserv;
            this->reserv_null;
        }

        Array(std::vector <std::string> str, std::vector <std::string> str_copy) {
            this->str;
            this->str_copy;
        }
        
        void Write_NumOfArrElem();
        void Write_LenOfWord();
        void Exercise_1();
        void Exercise_2();
        void Exercise_3();
        void Exercise_4();
        void PrintOriginalArray();
        void PrintConvertedArray();

};
