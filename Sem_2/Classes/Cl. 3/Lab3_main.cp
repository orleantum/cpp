#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
    Time a; // конструктор без параметров
    Time b; // конструктор без параметров
    Time c; // конструктор без параметров
    cin >> a; // ввод переменной
    cin >> b; // ввод переменной
    ++a; // операция инкремент
    cout << a << endl; // вывод переменной
    c = (a++) + b; // сложение и постфиксная операция инкремент
    cout << "a = " << a << endl; // вывод
    cout << "b = " << b << endl; // вывод
    cout << "c = " << c << endl; // вывод
    
    if (a == b)
        cout << "a == b " << endl;
    else
        cout << "a != b" << endl;
    
    return 0;
}
