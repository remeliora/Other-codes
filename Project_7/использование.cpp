//Класс "Автомобиль" и "Маршрутный лист" связаны отношением * использования * .
// 
//Использование – отношение между классами, при котором один класс в своей реализации 
//использует в той или иной форме реализацию объекта другого класса.
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    Car(string d, string m) {
        driver = d;
        model = m;
    }
    string Getdriver() {
        return driver;
    }
private:
    string driver;
    string model;
};

class RouteSheet {
public:
    RouteSheet(string a, Car& b, string t) {
        address = a;
        worker = b.Getdriver();
        time = t;
    }
    void print() {
        cout << "Работник: " << worker << endl;
        cout << "Адрес: " << address << endl;
        cout << "Время прибытия: " << time << endl;
    }
private:
    string address;
    string worker;
    string time;
};


int main()
{
    system("chcp 65001");   // для отображения русского языка
    system("cls");
    
    Car i = Car("Иванов И.И.", "Toyota Prius");
    RouteSheet r = RouteSheet("ул. Тихоокеанская, 138", i, "10:15");
    r.print();
}
