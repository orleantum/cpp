#include "Time.h"

using namespace std;

Time::Time(void)
{
    min = sec = 0;
}

Time::Time(int M, int S)
{
    min = M;
    sec = S;
}

Time::Time (const Time&t)
{
    min = t.min;
    sec = t.sec;
}

Time&Time::operator=(const Time &t)
{
    min = t.min;
    sec = t.sec;
    return *this;
}

Time Time::operator+(Time k)
{
    int t = min * 60 + sec;
    int kt = k.min * 60 + k.sec;
    t += kt;
    Time temp(t / 60, t % 60);
    return temp;
}

Time Time::operator+(int seconds) const {
    int total = min * 60 + sec + seconds;
    return Time(total / 60, total % 60);
}


ostream&operator<<(ostream&out, const Time&t)
{
    out << t.min << " : " << t.sec;
    return out;
}

istream&operator>>(istream&in, Time&t)
{
    cout << "\nEnter min: ";
    in >> t.min;
    cout << "\nEnter sec: ";
    in >> t.sec;
    return in;
}

Time::~Time() {}
