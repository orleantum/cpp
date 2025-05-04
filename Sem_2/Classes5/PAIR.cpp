#include "PAIR.h"

// конструктор без параметров
PAIR::PAIR()
{
    first = 0;
    second = 0;
}

// конструктор с параметрами
PAIR::PAIR(int f, int s)
{
    first = f;
    second = s;
}

// конструктор копирования
PAIR::PAIR(const PAIR& PAIR)
{
    first = PAIR.first;
    second = PAIR.second;
}

// деструктор
PAIR::~PAIR(void)
{
}

// модификаторы
void PAIR::Set_first(int f)
{
    first = f;
}

void PAIR::Set_second(int s)
{
    second = s;
}

// Перезагрузка операции сравнения
bool PAIR::operator>(const PAIR& p) const {
    return (first > p.first) || (first == p.first && second > p.second);
}

// глобальная функция для ввода
istream& operator>>(istream& in, PAIR& p) {
    cout << "Enter first: ";
    in >> p.first;
    cout << "Enter second: ";
    in >> p.second;
    return in;
}

// глобальная функция вывода
ostream& operator<<(ostream& out, const PAIR& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

void PAIR::Show()
{
    cout << "(" << first << ", " << second << ")";
}
