#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, tmp, max;
    cout << "Введите длину последовательности\n";
    cin >> n;
    cout << "Введите первое число\n";
    cin >> max;
    for (int i=2;i<=n;i++)
    {
        cout << "Введите следующее число: \n";
        cin >> tmp;
        if (tmp > max)
        {
            max = tmp;
        }
    }
    cout << "Максимальное число "<< max <<"\n";
    return 0;
}
