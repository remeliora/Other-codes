#include <iostream>
#include <cmath>
#include "Point.h"

void Point::Write() {
    std::cout << "Enter 2 numbers: ";
    std::cin >> m_x >> m_y;
}

void Point::Print() {
    double dm_y = static_cast<double>(m_y)/100;
    double dm_x = static_cast<double>(m_x);
    
    //res = dm_x + dm_y;

    if ((dm_x < 0) && (dm_y > 0)) {
        dm_y = dm_y * (-1);
        //res = dm_x + dm_y;
    }
    else if ((dm_x > 0) && (dm_y < 0)) {
        dm_x = dm_x * (-1);
        //res = dm_x + dm_y;
    }
    else if ((dm_x < 0) && (dm_y < 0)) {
        //res = dm_x + dm_y;
    }
    
    res = dm_x + dm_y;

    std::cout << "Rezulte of program: (" << res << ")";
}

std::ostream& operator << (std::ostream &out, Point &a) {
    //out << a.m_x << ", " << a.m_y;
    out << "Rezulte of program: (" << a.res << ")";
    return out;
}