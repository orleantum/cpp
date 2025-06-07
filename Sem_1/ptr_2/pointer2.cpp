#include <iostream>
using namespace std;
int main()
{
    int n,c;
    int *ptr1;
    int *ptr2;
    cin >> n >> c;
    ptr1 = &n;
    ptr2 = &c;
    cout << *ptr1 + *ptr2 << endl;
}

