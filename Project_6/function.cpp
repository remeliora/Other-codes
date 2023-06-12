#include <iostream>
#include "function.h"

using std::cout;

void seasonMonth (int value) {
     switch (value) {
        case 1:case 2: case 12: {cout << "Winter"; break;}
        case 3: case 4:case 5:{cout << "Spring"; break;}
        case 6:case 7:case 8:{cout << "Summer"; break;}
        case 9:case 10:case 11:{cout << "Autumn"; break;}
        default: cout << "Error" << std::endl;
    }
}
