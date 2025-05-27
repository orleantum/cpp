#include <iostream>
#include <vector>
#include <cstdlib>
#include "Money.h"

using namespace std;

typedef vector<Money>Vec;

Vec make_vector(int n)
{
    Vec v;
    for(int i = 0; i < n; i++)
    {
        int rub = rand() % 100;
        int penny = rand() % 100;
        v.push_back(Money(rub, penny));
    }
    return v;
}

void print_vector(Vec v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

Money min(Vec v)
{
    Money m = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    return m;
}

Money max(Vec v)
{
    Money m = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (m < v[i])
        {
            m = v[i];
        }
    }
    return m;
}

void add_back(Vec &v, const Money& m)
{
    v.push_back(m);
}

void deleteAt(Vec&v, int tmp)
{
    v.erase(v.begin()+tmp);
}

void add_to_all(Vec &v, const Money& Add)
{
    for(int i = 0; i < v.size(); i++)
    {
        v[i] = v[i] + Add;
    }
}

int main()
{
    try
    {
        vector<Money> v;
        vector<Money>::iterator vi = v.begin();
        int n, tmp;
        cout << "n ?" << endl;
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        Money n_min = min(v);
        add_back(v, n_min);
        print_vector(v);
        cin >> tmp;
        deleteAt(v, tmp);
        print_vector(v);
        Money n_max = max(v);
        Money sum = n_max + n_min;
        add_to_all(v, sum);
        print_vector(v);
    }
    catch(int)
    {
        cout << "error" << endl;
    }
}
