#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int tmp, previous;
    bool increas = true, decreas = true;

    cout << "Введите первое число, не 0 \n";
    cin >> tmp;
    previous = tmp;
    while (true)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            break;
        }
        else
        {
            if (tmp < previous)
            {
                increas = false;
            }
            else if (tmp > previous)
            {
                decreas = false;
            }
            previous = tmp;
        }
    }
    if (increas)
        cout << "Числа упорядочены по возрастанию\n";
    else if (decreas)
        cout << "Числа упорядочены по убыванию\n";
    else
        cout << "Числа не упорядочены\n";

    return 0;
}
