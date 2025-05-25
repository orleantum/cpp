#pragma once
#include "Vector.h"
#include "Student.h"
#include <string>

class Dialog {
private:
    Vector group;
    bool running;

public:
    Dialog();
    void Execute();
};
