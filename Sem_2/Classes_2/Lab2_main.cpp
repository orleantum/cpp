#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

// Функция для возврата объекта как результата

Student make_Student()
{
    string name;
    string group;
    float avg_score;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter group: ";
    cin >> group;
    cout << "Enter avg_score: ";
    cin >> avg_score;
    Student p(name, group, avg_score);
    return p;
}

// Функция для передачи объекта как параметра
void print_Student(Student p)
{
    p.show();
}

int main()
{
    // конструктор без параметров
    Student s1;
    s1.show();
    
    // констуктор с параметрами
    Student s2("Andrey", "ABC", 4.5);
    s2.show();
    
    // конструктор копирования
    Student s3 = s2;
    s3.set_name("Roman");
    s3.set_group("ACD");
    s3.set_avg_score(4.4);
    
    // конструктор копирования
    print_Student(s3);
    
    // конструктор копирования
    s1 = make_Student();
    s1.show();
}
