#include <iostream>
#include <map>
#include "Money.h"
#include "Money.cpp"

using namespace std;

typedef map<int, Money> TMap;
typedef vector<Money> Vec;

TMap make_map(int n)
{
    TMap m;
    Money a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        m[i] = a;
    }
    return m;
}

void print_map(const TMap& m)
{
    for (const auto& [key, value] : m)
    {
        cout << key << ": " << value << endl;
    }
}

Money min_value(const TMap& m)
{
    auto it = min_element(m.begin(), m.end(), [](const auto& lhs, const auto& rhs){
        return lhs.second < rhs.second;
    });
    return it->second;
}

Money max_value(const TMap& m)
{
    auto it = max_element(m.begin(), m.end(), [](const auto& lhs, const auto& rhs){
        return lhs.second < rhs.second;
    });
    return it->second;
}

void add_back(TMap& m, const Money& value)
{
    int new_key = m.empty() ? 0 : m.rbegin()->first + 1;
    m[new_key] = value;
}

void delete_by_key(TMap& m, int key)
{
    m.erase(key);
}

void add_to_all(TMap& m, const Money& value)
{
    for (auto& [key, val] : m)
    {
        val = val + value;
    }
}

int main()
{
    TMap m;
    int n;
    cout << "n ? ";
    cin >> n;

    m = make_map(n);
    print_map(m);

    Money min_val = min_value(m);
    add_back(m, min_val);
    cout << "\nAfter adding min:\n";
    print_map(m);

    int key_to_delete;
    cout << "\nEnter key to delete: ";
    cin >> key_to_delete;
    delete_by_key(m, key_to_delete);
    cout << "\nAfter deletion:\n";
    print_map(m);

    Money max_val = max_value(m);
    Money sum = min_val + max_val;
    add_to_all(m, sum);
    cout << "\nAfter adding (min + max) to all:\n";
    print_map(m);

    return 0;
}
