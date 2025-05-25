#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Vector x(3);            // вектор из 3 элементов (по умолчанию 0)
        cin >> x;               // ввод значений
        cout << "x = " << x;

        // Проверка []
        cout << "Index? ";
        int i;
        cin >> i;
        cout << "x[" << i << "] = " << x[i] << endl;

        // Проверка ()
        cout << "Size of x: " << x() << endl;

        // Проверка + число
        Vector y = x + 5;
        cout << "x + 5 = " << y;

        // Проверка - n
        Vector z = x - 1;
        cout << "x - 1 = " << z;

        // Проверка префиксного --
        --x;
        cout << "After --x: " << x;

        // Ещё раз
        --x;
        cout << "After --x again: " << x;

        // Попытка удалить из пустого
        --x;
    }
    catch(error e) {
        e.what(); // покажет сообщение об ошибке
    }

    return 0;
}
