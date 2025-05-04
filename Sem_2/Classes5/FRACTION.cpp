#include "FRACTION.h"

FRACTION::FRACTION() : PAIR() {}

FRACTION::FRACTION(int integerPart, int fractionalPart)
    : PAIR(integerPart, fractionalPart) {}

FRACTION::FRACTION(const FRACTION& f)
    : PAIR(f.first, f.second) {}

bool FRACTION::operator==(const FRACTION& f) const {
    return first == f.first && second == f.second;
}

bool FRACTION::operator!=(const FRACTION& f) const {
    return !(*this == f);
}

bool FRACTION::operator<(const FRACTION& f) const {
    return (first < f.first) || (first == f.first && second < f.second);
}

bool FRACTION::operator<=(const FRACTION& f) const {
    return (*this < f) || (*this == f);
}

bool FRACTION::operator>(const FRACTION& f) const {
    return (first > f.first) || (first == f.first && second > f.second);
}

bool FRACTION::operator>=(const FRACTION& f) const {
    return (*this > f) || (*this == f);
}

void FRACTION::Show() {
    cout << first << "." << second << endl;
}
