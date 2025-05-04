#include "Vector.h"
#include <iostream>
using namespace std;

// конструктор с параметрами
Vector::Vector(int s, int k)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = k;
    
    beg.elem = &data[0];
    end.elem = &data[size];
}

// конструктор копирования
Vector::Vector(const Vector& a)
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = a.data[i];
    
    beg = a.beg;
    end = a.end;
}

// деструктор
Vector::~Vector()
{
    delete[] data;
    data = 0;
}

// операция присваивания
Vector&Vector::operator = (const Vector& a)
{
    if (this == &a) return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int [size];
    for (int i = 0; i < size; i++) data[i] = a.data[i];
    
    beg.elem = data;
    end.elem = data + size;
    
    return *this;
}

// Операция доступа по индексу
int&Vector::operator[](int index)
{
    if (index < size) return data[index];
    else
    {
        cout << "\nError! Index out of bounds: " << index << endl;
        static int dummy = 0; // "заглушка", на которую можно безопасно вернуть ссылку
        return dummy;
    }
}

// Операция для добавления константы
Vector Vector::operator+(const int k) // +k
{
    Vector temp(size);
    for (int i = 0; i < size; ++i)
        temp.data[i] = data[i] + k;
    return temp;
}

// Операция для получения длины вектора
int Vector::operator()()
{
    return len();
}

// операция для ввода
ostream&operator<<(ostream& out, const Vector&a)
{
    for (int i = 0; i < a.len(); ++i) out << a.data[i] << " ";
    
    return out;
}

// операция для вывода
istream&operator>>(istream&in, Vector&a)
{
    for (int i = 0; i < a.len(); ++i) in >> a.data[i];
    
    return in;
}
