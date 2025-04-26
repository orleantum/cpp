#include "fraction.h"
#include <iostream>

using namespace std;

// Реализация метода для инициализации полей структуры
void fraction::Init(int F, int S)
{
    first = F;
    second = S;
}

// Реализация метода для чтения значений полей структуры
void fraction::Read()
{
    cout << "first? ";
    cin >> first;
    
    cout << "second? ";
    cin >> second;
}

// Реализация метода для вывода значений полей структуры
void fraction::Show()
{
    cout << "\nfirst = " << first;
    cout << "\nsecond = " << second;
    cout << "\n";
}

// Метод для возведения в степень
double fraction::Power()
{
    return pow(first, second);
}


int fraction::Ipart()
{
    if (second == 0)
        {
            cout << "Error: div by zero!" << endl;
            return 0; // Или можно бросить исключение, но пока сделаем просто
        }
    return static_cast<int>(first / second);
}
