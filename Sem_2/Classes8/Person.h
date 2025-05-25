#pragma once
#include "Object.h"
#include <string>

class Person : public Object {
protected:
    std::string name;
    int age;

public:
    Person();
    virtual ~Person();
    void Input() override;
    void Show() override;
    void HandleEvent(const TEvent& e) override {} // пустая реализация
};
