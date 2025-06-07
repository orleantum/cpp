#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N, S;
    cin >> N;
    if(N < 4)
    {
        cout << "number > 3\n";
    }
    else
    {
        S = sqrt(N);
        for (int i=0;i<S;i++)
        {
            for (int j=0;j<S;j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    return 0;
}
