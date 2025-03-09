#include <iostream>

using namespace std;

void output(int size, int* a, int* b, int* c) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << "   " << b[i] << "   " << c[i] << endl;
    }
}

int ftp(int size, int* array, int g) {
    for (int i = 0; i < size; i++) {
        if (g == 1 && array[i] != 0) {
            return i - 1;
        }
        else if (array[i] != 0) {
            return i;
        }
    }
    return size - 1;
}

void first(int size, int from, int* a, int* b, int* c) {
    int an = ftp(size, a, 1);
    if (from == 2) {
        int bn = ftp(size, b, 0);
        a[an] = b[bn];
        b[bn] = 0;
    }
    else {
        int cn = ftp(size, c, 0);
        a[an] = c[cn];
        c[cn] = 0;
    }
    output(size, a, b, c);
}

void second(int size, int from, int* a, int* b, int* c) {
    int bn = ftp(size, b, 1);
    if (from == 1) {
        int an = ftp(size, a, 0);
        b[bn] = a[an];
        a[an] = 0;
    }
    else if (from == 3) {
        int cn = ftp(size, c, 0);
        b[bn] = c[cn];
        c[cn] = 0;
    }
    output(size, a, b, c);
}

void third(int size, int from, int* a, int* b, int* c) {
    int cn = ftp(size, c, 1);
    if (from == 1) {
        int an = ftp(size, a, 0);
        c[cn] = a[an];
        a[an] = 0;
    }
    else if (from == 2) {
        int bn = ftp(size, b, 0);
        c[cn] = b[bn];
        b[bn] = 0;
    }
    output(size, a, b, c);
}

void hanoi_tower(int size, int from, int to, int buf_peg, int* a, int* b, int* c, int s)
{
    if (size != 0)
    {
        hanoi_tower(size - 1, from, buf_peg, to, a, b, c, s);

        cout << from << " -> " << to << endl;
        switch (to) {
        case 1:
            first(s, from, a, b, c);
            break;
        case 2:
            second(s, from, a, b, c);
            break;
        case 3:
            third(s, from, a, b, c);
            break;
        }

        hanoi_tower(size - 1, buf_peg, to, from, a, b, c, s);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int start_peg, destination_peg, buffer_peg;
    const int size = 6;

    start_peg = 1;
    buffer_peg = 2;
    destination_peg = 3;

    int a[size], b[size], c[size];
    for (int i = 0; i < size; i++) {
        a[i] = i + 1;
        b[i] = 0;
        c[i] = 0;
        cout << a[i] << "   " << b[i] << "   " << c[i] << endl;
    }
    cout << endl;

    hanoi_tower(size, start_peg, destination_peg, buffer_peg, a, b, c, size);
    return 0;
}