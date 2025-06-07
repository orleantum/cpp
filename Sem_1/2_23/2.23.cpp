#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float n, tmp, max = 0, count = -1;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        tmp = sin(n+i/n);
        if (tmp > max)
        {
            max = tmp;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        tmp = sin(n+i/n);
        if (tmp == max)
        {
            count++;
        }
    }
    cout << "Наибольшее число " << max << ", совпадений " << count << endl;
    return 0;
}

