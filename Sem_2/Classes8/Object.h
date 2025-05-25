#pragma once
#include <string>

class TEvent;

class Object {
public:
    Object() {}
    virtual ~Object() {}
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& e) = 0;
};
