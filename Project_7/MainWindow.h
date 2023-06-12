#pragma once
#include "MainWindow.h"
#include <SFML/Graphics.h>

class MainWindow
{
private:
    sf::RenderWindow m_window;
    double m_width;
    double m_height;



public:
    MainWindow(int width, int height);
    void Run();
    void Shape1();
    void Shape2();
    void Triangle();


};






