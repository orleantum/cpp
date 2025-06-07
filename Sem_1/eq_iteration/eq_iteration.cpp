// f'max(a)=2; (b)=3
// r = 3
// f'(x)>0 => -1/r < lambda < 0   => -0.7 < lambda < 0
// lambda = -0.4

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float x, xPerv;
    double eps = 0.000001;
    double lambda = -0.4;
    x = 1;
    xPerv = -1;
    
    while (abs(x-xPerv)>eps)
    {
        xPerv = x;
        x = lambda * (pow(xPerv, x) - pow(xPerv, -x) - 2);
    }
    cout << "Корень по методу итераций: " << x << endl;
    return 0;
}

