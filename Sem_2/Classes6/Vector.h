#pragma once
#include <iostream>
using namespace std;

class Vector; // предварительное объвление

class Iterator
{
    friend class Vector; // дружественный класс
    
public:
    Iterator() { elem = nullptr; } // конструктор без параметров
    Iterator(const Iterator&it) { elem = it.elem; } // конструктор копирования
    
    // Перегруженные операции сравнения
    bool operator == (const Iterator&it) { return elem == it.elem; }
    bool operator != (const Iterator&it) { return elem != it.elem; }
    
    // Перегруженная операция инкремент
    void operator++() { ++elem; }
    
    // Перегруженная операция декремент
    void operator--() { --elem; }
    
    // Перегруженная операция разыменования
    int& operator *() const{ return*elem; }
    
private:
    int* elem; // Указатель на элемент типа int
};

class Vector
{
public:
    // Конструктор с параметрами: выделяет
    // память под s элементов и заполняет их
    // значением k
    Vector(int s, int k = 0);
    Vector(const Vector&a); // конструктор с параметрами
    ~Vector(); // деструктор
    // операторо присваивания
    Vector&operator=(const Vector&a);
    // Операция доступа по индексу
    int&operator[](int index);
    // Операция для добавления константы
    Vector operator+(const int k);
    // Операция, возвращающая длину вектора
    int operator()();
    
    int len() const { return size; }
    
    // Перегруженные операции ввода-вывода
    friend ostream& operator << (ostream& out, const Vector&a);
    friend istream& operator>>(istream& in, Vector&a);
    
    Iterator first() { return beg; } // Возврвщает указатель на первый элемент
    Iterator last() { return end; } // Возвращает  указатель на элемент следующий за последним
    
private:
    int size; // размер вектора
    int* data; // Указатель на динамический массив значений вектора
    
    Iterator beg; // Указатель на первый элемент вектора
    Iterator end; // Указатель на элемент следующий за последним
};
