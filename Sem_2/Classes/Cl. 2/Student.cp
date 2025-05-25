#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

// конструктор без параметров
Student::Student()
{
    name="";
    group = "";
    avg_score = 0;
    
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

// конструктор с параметрами
Student::Student(string N, string K, float S)
{
    name = N;
    group = K;
    avg_score = S;
    cout << "Constructor s parametrami dlia objecta" << this << endl;
}

// конструктор копирования
Student::Student(const Student &t)
{
    name = t.name;
    group = t.group;
    avg_score = t.avg_score;
    cout << "Constructor copirovania dlia objecta" << this << endl;
}

// деструктор
Student::~Student()
{
    cout << "Destructor dlia objecta" << this << endl;
}

// селекторы
string Student::get_name()
{
    return name;
}

string Student::get_group()
{
    return group;
}

double Student::get_avg_score()
{
    return avg_score;
}

// модификаторы
void Student::set_name(string N)
{
    name = N;
}

void Student::set_group(string K)
{
    group = K;
}

void Student::set_avg_score(float S)
{
    avg_score = S;
}

// Метод для просмотра атрибутов
void Student::show()
{
    cout << "name: " << name << endl;
    cout << "group: " << group << endl;
    cout << "avg_score: " << avg_score << endl;
}
