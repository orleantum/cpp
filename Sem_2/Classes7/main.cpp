#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

int main()
{
    Time t;
    cin >> t;
    cout << "Time: " << t;
    
    int k;
    cout << "\nEnter seconds to add: ";
    cin >> k;
    Time p;
    p = t + k;
    cout << "Time: " << p;
    
    // инициализация, ввод и вывод значений вектора
    Vector<int>A(5, 0);
    cout << "\nEnter 5 nums: ";
    cin >> A;
    cout << "\nVector A: " << A << endl;
    
    // Инициализация и вывод значений вектора
    Vector <int>B(10, 1);
    cout << "\nVector B: " << B << endl;
    
    // операция присваивания
    B = A;
    cout << "\nB = A: " << B << endl;
    
    // доступ по индексу
    cout << "\nA[2]: "<< A[2] << endl;
    
    // получение длины вектора
    cout << "\nVector A size = " << A() << endl;
    
    // операция сложения с константой
    B = A + 10;
    cout << "\nB = A + 10 = " << B << endl;
    return 0;
}
