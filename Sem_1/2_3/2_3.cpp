#include <iostream>

using namespace std;

int main()
{
    int N, counter = 3, mult, sum = 0;

    cin >> N;

    cout << "S = ";

    for (int i = 0; i < N; i++)
    {
        mult = 1;
        for (int j = i + 1; j < counter; j++)
        {
            mult *= j;
            if (j < counter - 1)
            {
                cout << j << " * ";
            }
            else
            {
                cout << j;
            }
        }
        sum += mult;
        if (i < N - 1)
        {
            cout << " + ";
        }
        counter += 2;
    }

    cout << " = " << sum;
}