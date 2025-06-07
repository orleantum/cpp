#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, n;
    float fact = 1;
    cin >> x >> n;
    float sum = 1 + x;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
        sum += (pow(x, i))/fact;
    }
    cout << sum << endl;
    return 0;
}
