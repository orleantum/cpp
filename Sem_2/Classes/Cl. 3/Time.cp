#include "Time.h"
#include <iostream>

using namespace std;

// Переграузка операции присваивания
Time&Time::operator = (const Time&t)
{
    // проверка на самоприсваивание
    if (&t==this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}

// Перегрузка префиксной операции инкремент
Time&Time::operator++()
{
    int temp = min*60+sec;
    temp++;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}

// Перегрузка постфиксной операции инкремент
Time Time::operator ++(int)
{
    int temp = min * 60 + sec;
    temp++;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}

// Перегрузка бинарной операции сложения
Time Time::operator+(const Time&t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 + temp2) / 60;
    p.sec = (temp1 + temp2) % 60;
    return p;
}

// Перегрузка бинарной операции сравнения
bool Time::operator==(const Time& t) const
{
    return (min == t.min) && (sec == t.sec);
}

// Перегрузка глобальной функции-операции ввода
istream& operator >> (istream&in, Time&t)
{
    cout << "min? "; in >> t.min;
    cout << "sec? "; in >> t.sec;
    return in;
}

// Перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Time& t)
{
    out << t.min << ":";
    if (t.sec < 10)
        out << "0";
    out << t.sec;
    return out;
}
