#include <iostream>
#include "FRACTION.h"
using namespace std;

int main() {
    FRACTION a(3, 5);  // 3 целых, 5 десятых
    FRACTION b(4, 7);  // 3 целых, 7 десятых

    cout << "a: " << a << "\nb: " << b << endl;

    if (a < b) cout << "a < b\n";
    else if (a == b) cout << "a == b\n";
    else cout << "a > b\n";

    return 0;
}
