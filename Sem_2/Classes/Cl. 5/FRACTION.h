#pragma once
#include "PAIR.h"

class FRACTION : public PAIR
{
public:
    FRACTION(void);
    FRACTION(int integerPart, int fractionalPart);
    FRACTION(const FRACTION& f);
    void Show();
    
    // перегрузка операторов сравнения
    bool operator==(const FRACTION& f) const;
    bool operator!=(const FRACTION& f) const;
    bool operator<(const FRACTION& f) const;
    bool operator<=(const FRACTION& f) const;
    bool operator>(const FRACTION& f) const;
    bool operator>=(const FRACTION& f) const;
};
