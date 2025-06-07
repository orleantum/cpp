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
        for (int j=1;j<=N;j++)
        {
            cout << "* ";
        }
        cout << endl;
        for (int i=1;i<=N-2;i++)
        {
            cout << "* ";
            for (int j=1;j<=N-2;j++)
            {
                cout << "  ";
            }
            cout << "* ";
            cout << endl;
        }
        for (int j=1;j<=N;j++)
        {
            cout << "* ";
        }
    }
    return 0;
}
