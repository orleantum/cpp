#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, c, x1, x2, d;
    cin >> a >> b >> c;
    d = pow(b, 2) - 4*a*c;
    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / 2*a;
        x2 = (-b - sqrt(d)) / 2*a;
        cout << "x1 = " << x1 << "x2 = " << x2 << endl;
    }
    else if (d == 0)
    {
        x1 = (-b) / (2*a);
        cout << "x1 = x2 = " << x1;
    }
    else
    {
        cout << "Корней нет\n";
    }
    return 0;
}
    
