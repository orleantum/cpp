#include <iostream>
#include "Money.h"
#include "Money.cpp"
#include <vector>
#include <stack>

typedef stack<Money>St;
typedef vector<Money>Vec;

St make_stack(int n)
{
    St s;
    Money m;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        s.push(m);
    }
    return s;
}

Vec copy_stack_to_vector(St s)
{
    Vec v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

St copy_vector_to_steck(Vec v)
{
    St s;
    for(int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}

void print_stack(St s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void print_vec(const Vec& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
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
    Money m;
    St s;
    int n;
    cout << "n ?" << endl;
    cin >> n;
    s = make_stack(n);
    Vec v = copy_stack_to_vector(s);
    print_stack(s);
    Money min_val = min(v);
    add_back(v, min_val);
    print_vec(v);
    int tmp;
    cin >> tmp;
    deleteAt(v, tmp);
    print_vec(v);
    Money max_val = max(v);
    Money sum = min_val + max_val;
    add_to_all(v, sum);
    print_vec(v);
    return 0;
}
