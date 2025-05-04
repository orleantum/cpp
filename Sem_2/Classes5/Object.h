#pragma once

class Object
{
public:
    Object(void);
    ~Object(void);
    virtual void Show() = 0; // чисто виртуальная функция
};
