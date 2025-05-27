#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class Vector
{
    vector<T> v;
    int len;
public:
    Vector();
    Vector(int n);
    Vector(const Vector<T>&);
    void Print();
    T min();
    T max();
    void del(int tmp);
    void add_to_all(const T& Add);
};

template <class T>
Vector<T>::Vector()
{
    len = 0;
}

template <class T>
Vector<T>::Vector(int n)
{
    T a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    len = v.size();
}

template <class T>
Vector<T>::Vector(const Vector<T> &Vec)
{
    v = Vec.v;
    len = v.size();
}

template <class T>
void Vector<T>::Print()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
T Vector<T>::min()
{
    T m = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    v.push_back(m);
    len = v.size();
    return m;
}

template <class T>
T Vector<T>::max()
{
    T m = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (m < v[i])
        {
            m = v[i];
        }
    }
    return m;
}

template <class T>
void Vector<T>::del(int tmp)
{
    if (tmp >= 0 && tmp < v.size())
    {
        v.erase(v.begin() + tmp);
        len = v.size();
    }
}

template <class T>
void Vector<T>::add_to_all(const T& Add)
{
    for(int i = 0; i < v.size(); i++)
    {
        v[i] = v[i] + Add;
    }
}
