#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, sum = 0;
    cin >> n;
    while (n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}
