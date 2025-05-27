#pragma once
#include <iostream>

using namespace std;

class Money {
    long rub;
    int penny;
public:
    Money() {rub = 0; penny = 0;};
    Money(long r, int p) {
        rub = r;
        penny = p;
    };
    Money(const Money& temp) {
        rub = temp.rub;
        penny = temp.penny;
    };
    ~Money() {};

    int get_rub() { return rub; };
    int get_penny() { return penny; };

    void set_rub(long r) { rub = r; }
    void set_penny(int p) { penny = p; }

    Money& operator =(const Money&);
    Money& operator ++();
    Money operator ++(int);
    Money operator +(const Money&);
    Money operator /(const Money& temp);
    Money operator *(double value) const;
    bool operator<(const Money& other) const {
        return (rub * 100 + penny) < (other.rub * 100 + other.penny);
    }

    friend istream& operator >>(istream& in, Money& temp);
    friend ostream& operator <<(ostream& out, const Money& temp);
};
