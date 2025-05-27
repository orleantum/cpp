#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

typedef multiset<float> TSet;

TSet make_set(int n) {
    TSet s;
    float x;
    for (int i = 0; i < n; ++i) {
        cout << "? ";
        cin >> x;
        s.insert(x);
    }
    return s;
}

void print_set(const TSet& s) {
    for (float val : s)
        cout << val << " ";
    cout << endl;
}

float min_value(const TSet& s) {
    return *s.begin(); // multiset упорядочен
}

float max_value(const TSet& s) {
    return *s.rbegin(); // multiset упорядочен
}

void add_min_to_end(TSet& s) {
    float min = min_value(s);
    s.insert(min);
}

void delete_by_key(TSet& s, float key) {
    auto it = s.find(key);
    if (it != s.end()) s.erase(it);
}

void add_min_max_to_all(TSet& s) {
    float delta = min_value(s) + max_value(s);
    TSet result;
    for (float val : s) result.insert(val + delta);
    s = result;
}

int main() {
    int n;
    cout << "N? ";
    cin >> n;
    TSet s = make_set(n);
    print_set(s);

    add_min_to_end(s);
    cout << "After adding min to end:\n";
    print_set(s);

    float key;
    cout << "Key to delete: ";
    cin >> key;
    delete_by_key(s, key);
    cout << "After deletion:\n";
    print_set(s);

    add_min_max_to_all(s);
    cout << "After adding min + max to all:\n";
    print_set(s);

    return 0;
}
