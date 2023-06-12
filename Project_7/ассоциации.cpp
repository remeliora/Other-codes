// Класс "Автомобиль", "Фирма производителя автомобиля", "Владелец автомобиля"

//Ассоциация – связь между объектами, создаваемыми на основе классов.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ManufacturingFirm {
public:
    ManufacturingFirm(string f) {
        firm = f;
    }
    string Getfirm() {
        return firm;
    }
private:
    string firm;
};

class Driver;
class Car {
public:
    Car(string m) {
        model = m;
    }
    Car(string m, ManufacturingFirm* fi) {
        model = m;
        f = fi;
    }
    void AddDriver(Driver* d) {
        driver = d;
    }
    void Info() {
        if (f) {
            cout << "Фирма: " << f->Getfirm() << endl;
        }
        cout << "Модель машины: " << model << endl;
    }

private:
    Driver* driver;
    ManufacturingFirm* f;
    string model;
};


class Driver {
public:
    Driver(string n){
        name = n;
    }
    void addCar(Car *c) {
        myCar = c;
        c->AddDriver(this);
    }
    string GetName() {
        return name;
    }
    void print() {
        cout << "Водитель: " << name << endl;
        if (myCar) {
            myCar->Info();
        }
    }
private:
    Car* myCar;
    string name;
};


int main()
{   
    system("chcp 65001");   // для отображения русского языка
    system("cls");
    
    ManufacturingFirm* mf = new ManufacturingFirm("Toyota");
    Car* c1 = new Car("Aqua", mf);
    Driver* d1 = new Driver("Tom");
    d1->addCar(c1);
    d1->print();
    Car* c2 = new Car("Prius", mf);
    d1->addCar(c2);
    d1->print();
}



