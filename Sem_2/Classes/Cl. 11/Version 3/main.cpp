#include "Vector.h"
#include <iostream>
#include "Money.h"
#include "Money.cpp"

int main()
{
    Vector<Money>vec(5);
    vec.Print();
    Money min = vec.min();
    vec.Print();
    int tmp;
    cin >> tmp;
    vec.del(tmp);
    vec.Print();
    Money max = vec.max();
    Money sum = min + max;
    vec.add_to_all(sum);
    vec.Print();
    return 0;
}
