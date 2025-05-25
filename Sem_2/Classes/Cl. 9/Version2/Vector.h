#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

class Vector
{
    int size;
    int *beg;
public:
    Vector() {
        size = 0;
        beg = 0;
    }
    
    Vector(int s);
    Vector(int s, int *mas);
    Vector(const Vector& v);
    ~Vector();
    
    const Vector& operator=(const Vector& v);
    int operator[](int i);
//    Vector operator+(int a);
    Vector operator--();
    
    int operator()() const;
    Vector operator+(int a) const;    // прибавить ко всем элементам
    Vector operator-(int n) const;    // удалить n элементов с конца
    
    friend ostream& operator<<(ostream& out,const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};
