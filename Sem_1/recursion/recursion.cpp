#include <iostream>
using namespace std;
int n;
int sum;
int foo(int n)
{
    if (n > 0)
    {
        sum += n%10;
        n /= 10;
        foo(n);
    }
    return sum;
}

int main()
{
    cin >> n;
    foo(n);
    cout << sum << endl;
    return 0;
}
