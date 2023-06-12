#include <iostream>
#include <cmath>
#include "Shape.h"

// std::ostream& operator << (std::ostream &out, Point &a) {
//     out << "Point (" << a.m_x << ", " << a.m_y << ", " << a.m_z << ")";
//     return out;
// }

// std::ostream& operator << (std::ostream &out, Shape &sh) {
//     return sh.Print(out);
// }

void Print_Points::WritePointsOfCircle() {
    std::cout << "Первая точка: ";
    std::cin >> m_x1;
    std::cout << "Вторая точка: ";
    std::cin >> m_y1;
    std::cout << "Третья точка: ";
    std::cin >> m_z1;
    std::cout << "Радиус: ";
    std::cin >> radius;
    // std::cout << m_x1 << " " << m_y1 << " " << m_z1 << " " << radius;
}

void Print_Points::WritePointsOfTriangle() {
    std::cout << "Первая вершина: ";
    std::cin >> m_x1 >> m_y1 >> m_z1;
    std::cout << std::endl;
    std::cout << "Вторая вершина: ";
    std::cin >> m_x2 >> m_y2 >> m_z2;
    std::cout << std::endl;
    std::cout << "Третья вершина: ";
    std::cin >> m_x3 >> m_y3 >> m_z3;
    std::cout << std::endl;
    // std::cout << m_x1 << " " << m_y1 << " "<< m_z1 << " "<< m_x2 << " "<< m_y2 << " "<< m_z2 << " "<< m_x3 << " "<< m_y3 << " "<< m_z3;
}

void Print_Points::SavePOC() {
    m_x1 = m_x1;
    m_y1 = m_y1;
    m_z1 = m_z1;
    radius = radius;
    // std::cout << m_x1 << " " << m_y1 << " " << m_z1 << " " << radius;
}

void Print_Points::SavePOT() {
    m_x1 = m_x1;
    m_y1 = m_y1;
    m_z1 = m_z1;
    m_x2 = m_x2;
    m_y2 = m_y2;
    m_z2 = m_z2;
    m_x3 = m_x3;
    m_y3 = m_y3;
    m_z3 = m_z3;
}

void Circle::PointsOfCircle() {
    static_cast<Print_Points *>( this )->SavePOC();
    std::cout << "(" << m_x1 << ", " << m_y1 << ", " << m_z1 << ")";
}

void Circle::POC_Print_Radius() {
    static_cast<Print_Points *>( this )->SavePOC();
    std::cout << radius;
}

void Triangle::PointsOfTriangle() {
    static_cast<Print_Points *>( this )->SavePOT();
    std::cout << "(" << m_x1 << ", " << m_y1 << ", " << m_z1 << ")";
    std::cout << ", ";
    std::cout << "(" << m_x2 << ", " << m_y2 << ", " << m_z2 << ")";
    std::cout << ", ";
    std::cout << "(" << m_x3 << ", " << m_y3 << ", " << m_z3 << ")";
}