#pragma once
class Arrays {
    private:
        int size;
        int* arr;
        int* mass;
    public:
        // Arrays () { //конструктор без параметра
        //     size = 1;
        //     arr = new int[size];
        //     for (int i = 0; i < size; i++) {
        //         arr[i] = 0;
        //     }   
        // }

        Arrays(int valueSize = 0) { //конструктор с параметром
            size = valueSize;
            arr = new int[size];
            mass = new int[size];
        }

        Arrays (const Arrays & sourse) { //конструктор копирования
            size = sourse.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = sourse.arr[i];
            }
            mass = new int[size];
            for (int i = 0; i < size; i++) {
                mass[i] = sourse.mass[i];
            }
        }

        void WriteSize ();
        void WriteElems ();
        void Transform ();
        void PrintElems ();

        Arrays operator = (Arrays af) {
            size = af.size;
            for (int i = 0; i < size; i++) {
                arr[i] = af.arr[i]; 
                mass[i] = af.mass[i];
                af.mass[i] = af.arr[i]; 
            }
            return *this;
        }

        ~Arrays () {
            delete[]arr;
        }
};