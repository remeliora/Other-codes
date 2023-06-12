#ifndef STACK_H
#define STACK_H
 
#include <cassert> // для assert
#include <iostream>
#include <iomanip> // для setw
using namespace std;

template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор
 
    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack();         // вывод стека на экран
};
 
// реализация методов шаблона класса STack
 
// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}
 
// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
    size(otherStack.getStackSize()) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под новый стек
    top = otherStack.getTop();
 
    for(int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}
 
// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}
 
// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    assert(top < size); // номер текущего элемента должен быть меньше размера стека
 
    stackPtr[top++] = value; // помещаем элемент в стек
}
 
// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0
 
    stackPtr[--top]; // удаляем элемент из стека
}
 
#endif // STACK_H