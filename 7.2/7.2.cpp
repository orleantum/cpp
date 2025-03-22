#include <iostream>

using namespace std;

int sum(int a, ...) {
    int sum = 0;
    int* p = &a;
    while (*p) {
        sum += *p;
        p += 2;
    }

    return sum;
}

int main() {
    cout << sum(1, 2, 3, 0) << endl;
    cout << sum(1, 2, 3, 4, 5, 6, 7, 0) << endl;
    cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0) << endl;
    return 0;
}