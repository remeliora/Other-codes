#pragma once
#include <iostream>

class Shape {
    public:
        virtual void Result() = 0;
        // virtual std::ostream& Print (std::ostream &out);
        // friend std::ostream& operator << (std::ostream &out, Shape &sh);
        // virtual ~Shape() {};
};

class Print_Points {
    protected:
        int m_x1, m_y1, m_z1, m_x2, m_y2, m_z2, m_x3, m_y3, m_z3, radius;
    public:
        // int m_x1, m_y1, m_z1, m_x2, m_y2, m_z2, m_x3, m_y3, m_z3, radius;
        Print_Points(int x1 = 1, int y1 = 2, int z1 = 3, int x2 = 4, int y2 = 5, int z2 = 6, int x3 = 7, int y3 = 8, int z3 = 9, int rad = 7): 
        m_x1(x1), m_y1(y1), m_z1(z1), m_x2(x2), m_y2(y2), m_z2(z2), m_x3(x3), m_y3(y3), m_z3(z3), radius(rad) {}
        // Print_Points(int x2 = 0, int y2 = 0, int z2 = 0): m_x2(x2), m_y2(y2), m_z2(z2) {}
        // Print_Points(int x3 = 0, int y3 = 0, int z3 = 0): m_x3(x3), m_y3(y3), m_z3(z3) {}
        // Print_Points(int rad = 0): radius(rad) {}
        void WritePointsOfCircle();
        void SavePOC();
        void WritePointsOfTriangle();
        void SavePOT();
        void Result(Shape* shape) {
            shape->Result();
        }
        ~Print_Points() {}
};

class Circle: public Print_Points, public Shape {
    public:
        // Circle(int x = 0, int y = 0, int z = 0, int r = 0): Print_Points(x, y, z, r) {}
        void PointsOfCircle();
        void POC_Print_Radius();
        void Result() override {
            std::cout << "Circle ("; 
            Circle::PointsOfCircle();
            std::cout << ") radius "; 
            Circle::POC_Print_Radius();
            std::cout << ")" << std::endl;
        }

};

class Triangle: public Print_Points, public Shape {
    public:
        void PointsOfTriangle();
        void Result() override {
            std::cout << "Triangle (";
            Triangle::PointsOfTriangle();
            std::cout << ")" << std::endl;
        }
};