#include <iostream>
#include "Arrays.h"

int main() {   
    system("chcp 65001");
    system("cls");

    Arrays *mas = new Arrays();
    mas->WriteSize();
    mas->WriteElems();
    mas->Transform();
    mas->PrintElems();
    delete []mas;
    
    return 0;
}