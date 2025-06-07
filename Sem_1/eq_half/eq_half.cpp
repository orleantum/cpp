#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;
    a = 0;
    b = 1;
    
    while (b-a > eps)
    {
        c = (a+b)/2;
        fA = pow(2.7, a) - pow (2.7, -a) - 2;
        fB = pow(2.7, b) - pow (2.7, -b) - 2;
        fC = pow(2.7, c) - pow (2.7, -c) - 2;
        if (fA * fC < 0)
        {
            b = c;
        }
        else if (fC * fB < 0)
        {
            a = c;
        }
        else
        {
            cout << "Что-то пошло не так!" << endl;
        }
    }
    cout << "Корни: " << a << "; " << b << endl;
    return 0;
}
