#pragma once
#include <iostream>

const int MAX_SIZE=30; // Максимальный размер вектора

class Vector
{
    int size; // Текущий размер
    int* beg; // Указатель на начало динамического массива
    
public:
    Vector(){size=0; beg=0;} // Конструктор без параметров
    Vector(int s); // Конструктор с параметром
    Vector(int s,int* mas); // Конструктор с параметром
    Vector(const Vector&v); // Конструктор копирования
    ~Vector(); // Деструктор
    const Vector& operator=(const Vector&v); // Операция присваивания
    int operator[](int i); // Доступ по индексу
//    Vector operator+(int a); // Добавление элемента
    Vector operator--(); // Удаление элемента
    
    int operator()() const;           // размер вектора
    Vector operator+(int a) const;    // прибавить ко всем элементам
    Vector operator-(int n) const;    // удалить n элементов с конца

    // Дружественные функции ввода-вывода
    friend std::ostream& operator<<(std::ostream&out,const Vector&v);
    friend std::istream& operator>>(std::istream& in, Vector&v);
};
