#include "MainWindow.h"

MainWindow::MainWindow(int width, int height) : m_window((width, height)),
                                                m_width(width),
                                                m_height(height)
void MainWindow::Run()
{
    while (m_window.isOpen())
    {
        /*for (sf::Event event = sf::Event{}; m_window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }*/
        m_window.clear();
        DrawShape1();
        DrawShape2();
        DrawTriangle();

        window.display();

        sf::sleep(sf::seconds(5));
    }
}

void MainWindow::DrawShape1()
{
    sf::CircleShape shape1(40);
    shape1.setPosition({200,120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0)); 
}

void MainWindow::DrawShape2()
{
    sf::RectangleShape shape2;
    shape2.setSize({120,15});
    shape2.setPosition({120,100});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
}

void MainWindow::DrawTriangle()
{
    sf::CircleShape triangle(80, 3);
    triangle.setPosition({50,250});
    triangle.setFillColor(sf::Color(100, 250, 50));
}

/*int main(){
    sf::RenderWindow window(sf::VideoMode({800,600}), "title");

    window.clear();

    sf::CircleShape shape1(40);
    shape1.setPosition({200,120});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({120,15});
    shape2.setPosition({120,100});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0xFF));
    window.draw(shape2);

    sf::CircleShape triangle(80, 3);
    triangle.setPosition({50,250});
    triangle.setFillColor(sf::Color(100, 250, 50));
    window.draw(triangle);

    window.display();

    sf::sleep(sf::seconds(5));

}*/