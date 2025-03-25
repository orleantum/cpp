#include <iostream>

using namespace std;

int main()
{
    int N, sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a = rand() % 10;
        sum += a;
        cout << a << " ";
    }

    cout << endl << sum;
}