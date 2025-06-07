#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    if (N < 3)
    {
        cout << "number > 2\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < N-i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}


