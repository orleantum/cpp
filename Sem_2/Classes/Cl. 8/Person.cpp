#include "Person.h"
#include <iostream>

Person::Person() : name(""), age(0) {}
Person::~Person() {}

void Person::Input() {
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
}

void Person::Show() {
    std::cout << "Имя: " << name << ", Возраст: " << age << std::endl;
}
