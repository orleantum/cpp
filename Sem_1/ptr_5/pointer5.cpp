#include <iostream>
using namespace std;
int main()
{
    int N, fact = 1;
    int *ptr = &fact;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        *ptr *= i;
    }
    cout << fact << endl;
    return 0;
}
