#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float n, tmp, nomer = 0, chislo = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        tmp = sin(n+i/n);
        if (tmp > chislo)
        {
            chislo = tmp;
            nomer = i;
        }
    }
    cout << "Наибольшее число " << chislo << ", его номер в последовательности " << nomer << endl;
    return 0;
}
