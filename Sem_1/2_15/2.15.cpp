#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, s, d;
    bool flag = false;
    cin >> n >> s;
    while (n > 0 && !flag)
    {
        d = n%10;
        if (s == d)
        {
            flag = true;
        }
        else
        {
            n /= 10;
        }
    }
    if (flag == true)
    {
        cout << "Найдена \n";
    }
    else
    {
        cout << "Не найдена \n";
    }
    return 0;
}
