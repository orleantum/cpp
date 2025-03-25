#include <iostream>

using namespace std;

int main()
{
    int N, mult = 1;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a = rand() % 10 + 1;
        mult *= a;
        cout << a << " ";
    }

    cout << endl << mult;
}