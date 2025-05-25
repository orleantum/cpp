#include "fraction.h"
#include <iostream>

using namespace std;

fraction make_fraction(int F, int S)
{
    fraction t; // Создали временную переменную
    t.Init(F, S); // Инициализировали поля переменной t с помощью параметров функции
    return t; // Вернули значение переменной t
}

int main()
{
    // Определение переменных A и B
    fraction A;
    fraction B;
    A.Init(3, 2); // Инициализация переменной A
    B.Read(); // Ввод полей переменных B
    A.Show(); // Вывод значений полей переменной A
    B.Show(); // Вывод значений полей переменной B
    // Вывод значения степени, вычисленного с помощью функции Power()
    cout << "A.Power(" << A.first << "," << A.second << ") = " << A.Power() << endl;
    cout << "B.Power(" << B.first << "," << B.second << ") = " << B.Power() << endl;
    cout << "A.Ipart(" << A.first << "," << A.second << ") = " << A.Ipart() << endl;
    
    // указатели
    fraction *X = new fraction; // Выделение памяти под динамическую переменную
    X->Init(2, 5); // инициализация
    X->Show(); // Вывод значений полей
    X->Power(); // Вычисление степени
    cout << "X->Power(" << X->first << "," << X->second << ") = " << X->Power() << endl;
    cout << "X->Ipart(" << X->first << "," << X->second << ") = " << X->Ipart() << endl;
    
    // массивы
    fraction arr[3]; // Определение массива
    for (int i = 0; i < 3; i++) arr[i].Read(); // Чтение значений полей
    for (int i = 0; i < 3; i++) arr[i].Show(); // Вывод значений полей
    for (int i = 0; i < 3; i++)
    {
        arr[i].Power(); // Вычсиление степени
        arr[i].Ipart();
        cout << "arr[" << i << "].Power(" << arr[i].first << "," << arr[i].second << ") = " << arr[i].Power() << endl;
        cout << "arr[" << i << "].Ipart(" << arr[i].first << "," << arr[i].second << ") = " << arr[i].Ipart() << endl;
    }
    
    // Вызов функции make_fraction()
    int y;
    int z;
    cout << "first?";
    cin >> y;
    cout << "second?";
    cin >> z;
    
    // Переменная F формируется с помощью функции make_fraction()
    fraction F = make_fraction(y, z);
    F.Show();
    cout << "F.Power(" << F.first << "," << F.second << ") = " << F.Power() << endl;
    cout << "F.Ipart(" << F.first << "," << F.second << ") = " << F.Ipart() << endl;
    
    return 0;
}
