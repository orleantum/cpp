#include <iostream>
using namespace std;

int main()
{
int n, tmp;
cin >> n;
for (int i=1; i <= n; i++)
{
tmp=n%10;
cout << tmp;
n /= 10;
}
cout << endl;
return 0;
}
