#pragma once
#include "Object.h"

class Vector {
private:
    Object** data;
    int size;
    int capacity;

public:
    Vector();
    ~Vector();
    bool Add(Object* obj);
    void Show();
    void RemoveLast();
    Object* Get(int index);
    int GetSize() const;
};
