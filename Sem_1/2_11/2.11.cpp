#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, tmp;
    bool positive = false;
    bool negative = false;
    cout << "Введите длину последовательности\n";
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cout << "Введите число: \n";
        cin >> tmp;
        if (!positive && !negative)
        {
            if (tmp > 0)
            {
                positive = true;
            }
            else if (tmp < 0)
            {
                negative = true;
            }
        }
    }
    if (positive)
    {
        cout << "Первое число положительное\n";
    }
    else if (negative)
    {
        cout << "Певрое число отрицательное\n";
    }
    else
    {
        cout << "Первое число 0\n";
    }
    return 0;
}
