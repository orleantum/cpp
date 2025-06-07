#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float x, xPerv;
    x = 1;
    xPerv = 0;
    double eps = 0.000001;
    while (abs(x-xPerv)>eps)
    {
        xPerv = x;
        x = xPerv - (pow(2.7, x) - pow(2.7, -x) - 2) / (pow(2.7, x) + pow(2.7, -x));
    }
    cout << "Корень: " << x << endl;
    return 0;
}

