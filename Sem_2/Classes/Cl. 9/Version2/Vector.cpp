#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

Vector::Vector(int s)
{
    if(s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
    size = s;
    beg = new int [s];
    for (int i = 0; i < size; i++)
        beg[i] = 0;
}

Vector::Vector(const Vector &v)
{
    size = v.size;
    beg=new int [size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}

Vector::~Vector()
{
    if (beg != 0) delete[] beg;
}

Vector::Vector(int s,int *mas)
{
    if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
    size = s;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = mas[i];
}

const Vector& Vector::operator=(const Vector& v)
{
    if (this == &v) return *this;
    if (beg != 0) delete[] beg;
    size = v.size;
    beg = new int [size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    
    return *this;
}

ostream& operator<<(ostream& out, const Vector& v)
{
    if (v.size == 0) out << "Empty\n";
    else
    {
        for (int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out<<endl;
    }
    
return out;
}

istream& operator>>(istream& in, Vector& v)
{
    for(int i = 0; i < v.size; i++)
    {
        cout << ">";
        in >> v.beg[i];
    }
    
    return in;
}

// Операция [] — доступ по индексу
int Vector::operator[](int i)
{
    if (i < 0) throw error("index <0");
    if (i >= size) throw error("index>size");
    return beg[i];
}

//Vector Vector::operator+(int a)
//{
//    if (size + 1 == MAX_SIZE) throw 4;
//    Vector temp(size + 1, beg);
//    temp.beg[size] = a;
//    
//    return temp;
//}

Vector Vector::operator--()
{
    if (size == 0) throw error("Vector is empty");
    if (size == 1)
    {
        size = 0;
        delete[] beg;
        beg = 0;
        return *this;
    }

    Vector temp(size, beg);
    delete[] beg;
    size--;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = temp.beg[i];
    
    return *this;
}

// Операция () — возвращает размер вектора
int Vector::operator()() const {
    return size;
}

// Операция + число — прибавляет ко всем элементам вектора
Vector Vector::operator+(int value) const {
    Vector temp(size);
    for (int i = 0; i < size; ++i)
        temp.beg[i] = beg[i] + value;
    return temp;
}

// Операция - n — удаляет n элементов с конца
Vector Vector::operator-(int n) const {
    if (n > size) throw error("Too many elements to remove");
    Vector temp(size - n);
    for (int i = 0; i < temp.size; ++i)
        temp.beg[i] = beg[i];
    return temp;
}
