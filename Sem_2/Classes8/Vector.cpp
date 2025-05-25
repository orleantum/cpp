#include "Vector.h"
#include <iostream>

Vector::Vector() : size(0), capacity(10) {
    data = new Object*[capacity];
}

Vector::~Vector() {
    for (int i = 0; i < size; ++i) delete data[i];
    delete[] data;
}

bool Vector::Add(Object* obj) {
    if (size < capacity) {
        data[size++] = obj;
        return true;
    } else {
        std::cout << "Группа переполнена.\n";
        return false;
    }
}

void Vector::Show() {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        data[i]->Show();
    }
}

void Vector::RemoveLast() {
    if (size > 0) {
        delete data[--size];
    }
}

Object* Vector::Get(int index) {
    if (index >= 0 && index < size) return data[index];
    return nullptr;
}

int Vector::GetSize() const {
    return size;
}
