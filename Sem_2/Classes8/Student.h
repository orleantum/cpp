#pragma once
#include "Person.h"

class Student : public Person {
private:
    float rating;

public:
    Student();
    ~Student();
    void Input() override;
    void Show() override;
};
