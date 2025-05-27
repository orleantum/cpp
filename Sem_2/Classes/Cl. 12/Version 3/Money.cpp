#include <iostream>
#include "Money.h"

using namespace std;

Money& Money::operator =(const Money& temp) {
    if (&temp == this) {return *this;}
    rub = temp.rub;
    penny = temp.penny;
    return *this;
}

Money& Money::operator ++() {
    int temp = rub * 100 + penny;
    temp++;
    rub = temp / 100;
    penny = temp % 100;
    return *this;
}

Money Money::operator ++(int) {
    int temp = rub * 100 + penny;
    temp++;
    Money t1(rub, penny);
    rub = temp / 100;
    penny = temp % 100;
    return t1;
}

Money Money::operator +(const Money& temp) {
    int t1 = rub * 100 + penny;
    int t2 = temp.rub * 100 + temp.penny;
    Money temp2;
    temp2.rub = (t1 + t2) / 100;
    temp2.penny = (t1 + t2) % 100;
    return temp2;
}

Money Money::operator /(const Money& temp) {
    int t1 = rub * 100 + penny;
    int t2 = temp.rub * 100 + temp.penny;

    Money result;

    int division = t1 / t2;

    result.rub = division;
    result.penny = (t1 * 100 / t2) % 100;

    return result;
}

Money Money::operator *(double value) const {
    int total_penny = rub * 100 + penny;
    long result_penny = total_penny * value;

    Money result;
    result.rub = result_penny / 100;
    result.penny = result_penny % 100;

    return result;
}

istream& operator >>(istream& in, Money& temp) {
    cout << "rub: ";
    in >> temp.rub;
    cout << "penny: ";
    in >> temp.penny;
    return in;
}

ostream& operator <<(ostream& out, const Money& temp) {
    return (out << temp.rub << "." << temp.penny);
}
