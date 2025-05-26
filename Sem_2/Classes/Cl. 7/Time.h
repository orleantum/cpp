#include <iostream>
using namespace std;

class Time
{
public:
    Time(void);
    Time(int, int);
    Time(const Time&);
    Time&operator = (const Time&);
    
    // Перегруженные операции ввода-вывода
    friend ostream& operator << (ostream& out, const Time&);
    friend istream& operator >> (istream& in, Time&);
    
    Time operator+(Time k);
    
    Time operator+(int seconds) const;

    
public:
    virtual ~Time(void);
    
private:
    int min, sec;
};
