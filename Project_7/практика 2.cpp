//Сформировать описание классов, связанных отношениями различных видов:
//1) Есть классы "Двигатель", "Паровой двигатель", "Дизель", "Двигатель внутреннего сгорания".Они связаны отношениями * наследования*;

//Наследование(одиночное) – отношение между классами, при котором один класс повторяет структуру и 
//поведение другого класса.

#include <iostream>
using namespace std;
class Engine {
public:
    Engine() { power = 0;}
    Engine(int a) { power = a;}
    void GetP() {
        cout << "Мощность двигателя: " << power << " л.с." << endl;
    }
private:
    int power;

};

class SteamEngine : public Engine {
public:
    SteamEngine(int s = 0, int e = 0 ): amountofwater(s), Engine(e) {}
    void GetW() {
        cout << "Кол-во воды: " << amountofwater <<" л." << endl;
    }
    /*void InfoSE() {
        GetW();
        GetP();
    }*/
private:
    int amountofwater; 
};

class InternalCombustionEngine : public Engine {
public:
    InternalCombustionEngine(double i = 0.0, int e = 0) : fuelConsumption(i), Engine(e) {}
    void GetF() {
        cout << "Расход топлива: " << fuelConsumption << " л." << endl;
    }
    /*void InfoICE() {
        GetP();
        GetF();
    }*/
private:
    double fuelConsumption;
};

class Diesel : public InternalCombustionEngine {
public:
    Diesel(int d = 0, double i = 0.0, int e = 0) : torque(d), InternalCombustionEngine(i, e) {}
    void GetT() {
        cout << "Вращающий момент: " << torque << " нм." << endl;
    }
    //void InfoD() {
    //    InfoICE();
    //    GetT();
    //}
private:
    int torque;
};

int main()
{
    system("chcp 65001");   // для отображения русского языка
    system("cls");
    
    Diesel di(20, 1.7, 200);
    di.GetP();
    di.GetF();
    di.GetT();

   /* Engine en(120);
    en.GetP();

    InternalCombustionEngine ice(1.4);
    ice.GetP();
    ice.GetF();*/
}

