#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N < 2)
    {
        cout << "number > 1\n";
    }
    else
    {
        for (int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    return 0;
}
