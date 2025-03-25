#include <iostream>

using namespace std;

int main()
{
    int N, mid, h;
    cin >> N;
    mid = N / 2; // Центр
    h = N - mid - 2; // Высота

    if (N > 3)
    {
        // Вершина
        for (int i = 0; i < mid; i++)
        {
            cout << " ";
        }

        for (int i = mid; i < N - mid; i++)
        {
            cout << "*";
        }

        for (int i = mid + 1; i < N; i++)
        {
            cout << " ";
        }
        cout << endl;
        int counter = 1;

        // Стороны
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < mid - counter; j++)
            {
                cout << " ";
            }
            
            cout << "*";

            for (int j = mid - counter; j < mid + counter - 1; j++)
            {
                cout << " ";
            }

            cout << "*";

            counter++;
            cout << endl;
        }

        // Основание
        for (int i = 0; i < N; i++)
        {
            cout << "*";
        }
    }
    else
    {
        cout << "N must be more than 3!";
    }
}