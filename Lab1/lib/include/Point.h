#pragma once
class Point {
    private:
        int m_x, m_y;
        double res; 
    public:
        Point(int x = 0, int y = 0, double res = 0.0):m_x(x), m_y(y), res(res) {}
        void Write();
        void Print();
        friend std::ostream& operator << (std::ostream &out, Point &a);
};