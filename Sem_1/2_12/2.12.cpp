#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, tmp, max, min;
    cout << "Введите длину последовательности\n";
    cin >> n;
    cout << "Введите первое число: \n";
    cin >> tmp;
    max = tmp;
    min = tmp;
    for (int i=2;i<=n;i++)
    {
        cout << "Введите следующее число: \n";
        cin >> tmp;
        if (tmp > max)
        {
            max = tmp;
        }
        else if (tmp < min)
        {
            min = tmp;
        }
    }
    cout << "Сумма максимального и минимального: " << max + min << endl;
    return 0;
}
