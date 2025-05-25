#pragma once
#include <iostream>
using namespace std;

struct PAIR
{
    // атрибуты
protected:
    int first;
    int second;
    
    PAIR(); // конструктор без параметров
    PAIR(int, int); // конструктор с параметрами
    PAIR(const PAIR&); // конструктор копирования
    virtual ~PAIR(void); // деструктор
    
    // селекторы
    int Get_first(){ return first; }
    int Get_second(){ return second; }
    
    // модификаторы
    void Set_first(int);
    void Set_second(int);
    
    // перегрузка операции присваивания
    bool operator>(const PAIR&p) const;
    
    // глобальные операторы-функции ввода-вывода
    friend istream& operator >> (istream&in, PAIR& p);
    friend ostream& operator << (ostream&out, const PAIR& p);
};
