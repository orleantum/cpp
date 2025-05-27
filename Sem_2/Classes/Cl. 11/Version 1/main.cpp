#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<int>Vec;

Vec make_vector(int n)
{
    Vec v;
    for(int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        v.push_back(a);
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

int min(Vec v)
{
    int m = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if(m > v[i])
        {
            m = v[i];
        }
    }
    return m;
}

int max(Vec v)
{
    int max = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if(max < v[i])
        {
            max = v[i];
        }
    }
    return max;
}

void add_back(Vec &v, int m)
{
    v.push_back(m);
}

void deleteAt(Vec&v, int tmp)
{
    v.erase(v.begin()+tmp);
}

void add(Vec&v, int Add)
{
    for(int i = 0; i < v.size(); i++)
    {
        v[i] += Add;
    }
}

int main()
{
    try
    {
        vector<int> v;
        vector<int>::iterator vi = v.begin();
         int n, tmp;
        cout << "n ?" << endl;
        cin >> n;
        v = make_vector(n);
        print_vector(v);
        int n_min = min(v);
        add_back(v, n_min);
        print_vector(v);
        cin >> tmp;
        deleteAt(v, tmp);
        print_vector(v);
        int n_max = max(v);
        int sum = n_max + n_min;
        add(v, sum);
        print_vector(v);
    }
    catch(int)
    {
        cout << "error";
    }
    return 0;
}
