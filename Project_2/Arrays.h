#pragma once
class Arrays {
    private:
        int size1, size2;
        int* arr;
        int* mass;
    public:
        Arrays(int valueSize = 0) {
            size1 = valueSize;
            arr = new int[size1];

        }
        void WriteSize ();
        void WriteElems ();
        void Transform ();
        void PrintElems ();
        ~Arrays () {
            delete[]arr;
        }
};