#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    d = n/2;
    // Задняя грань
    for (int i = 0; i < d; i++)
    {
     cout << " ";
    }
    for (int i = 0; i < n; i++)
    {
     cout << "* ";
    }
    cout << endl;
    // Верхние диагонали
    for (int i = 0; i < d-1; i++)
    {
     for (int j = 1; j < d-i; j++)
     {
     cout << " ";
     }
     cout << "* ";
     for (int j = 0; j < n-2; j++)
     {
     cout << " ";
     }
     cout << "*";
     for (int j = 0; j < i; j++)
     {
     cout << " ";
     }
     cout << "*" << endl;
    }
    // Передняя верхняя грань + кусок задней грани
    for (int i = 0; i < n; i++)
    {
     cout << "* ";
    }
    for (int i = 0; i < d-2; i++)
    {
     cout << " ";
    }
    cout << "*" << endl;
    // Боковые грани
    for (int i = 0; i < n-d-1; i++)
    {
     cout << "* ";
     for (int j = 0; j < n-2; j++)
     {
     cout << " ";
     }
     cout << "* ";
     for (int i = 0; i < d-2; i++)
     {
     cout << " ";
     }
     cout << "*" << endl;
    }
    // Нижние диагонали
    for (int i = 0; i < d-1; i++)
    {
     cout << "* ";
     for (int j = 0; j < n-2; j++)
     {
     cout << " ";
     }
     cout << "*";
     for (int j = 1; j < d-i-1; j++)
     {
     cout << " ";
     }
     cout << "*" << endl;
    }
    // Нижняя грань
    for (int i = 0; i < n; i++)
    {
     cout << "* ";
    }
    cout << endl;
    return 0;
}
