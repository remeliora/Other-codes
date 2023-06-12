//2) Классы "Автомобиль", "Двигатель", "Колесо" связаны отношением * агригации*;

//Агрегация – отношение между классами по типу «целая часть».
//Агрегируемый класс в той или иной форме является частью агрегата.

#include <iostream>

class Engine {
public:
    Engine(){
        power = 0;
    }
    Engine(int a) {
        power = a;
    }
    int GetP(){
        return power;
    }
private:
    int power;
};

class Wheel {
public:
    Wheel(){
        number = 0;
    }
    Wheel(int a) {
        number = a;
    }
    int GetN() {
        return number;
    }
private:
    int number;
};

class Car {
public:
    Car(){
        wheel = Wheel(4);
    }
    Car(int p) {
        wheel = Wheel(4);
        eng = Engine(p);
    }
    void Info() {
        std::cout << "Кол-во колес: " << wheel.GetN() << std::endl;
        if( eng.GetP() == 0){ std::cout << "Мощность двигателя: неизвестно"  << std::endl; }
        else std::cout << "Мощность двигателя: " << eng.GetP() << " л.с" << std::endl;
    }
private:
    Engine eng;
    Wheel wheel;
};


int main()
{
    system("chcp 65001");   // для отображения русского языка
    system("cls");
    
    Car c;
    c = Car(200);
    c.Info();
}
