#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class PAIR : public Object
{
public:
    PAIR(void); // конструктор без параметров
    PAIR(int, int); // конструктор с параметрами
    PAIR(const PAIR&); // конструктор копирования
    virtual ~PAIR(void); // деструктор
    void Show(); // чисто виртуальная функция
    
    // селекторы
    int Get_first(){ return first; }
    int Get_second(){ return second; }
    
    // модификаторы
    void Set_first(int);
    void Set_second(int);
    
    // перегрузка операции сравнения
    bool operator>(const PAIR&p) const;
    
    // глобальные операторы-функции ввода-вывода
    friend istream& operator >> (istream&in, PAIR& p);
    friend ostream& operator << (ostream&out, const PAIR& p);
    
protected:
    // атрибуты
    int first;
    int second;
};
