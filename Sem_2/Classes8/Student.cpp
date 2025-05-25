#include "Student.h"
#include <iostream>

Student::Student() : rating(0.0f) {}
Student::~Student() {}

void Student::Input() {
    Person::Input();
    std::cout << "Введите рейтинг: ";
    std::cin >> rating;
}

void Student::Show() {
    Person::Show();
    std::cout << "Рейтинг: " << rating << std::endl;
}
