#pragma once
#include <iostream>
#include <fstream>

class Time {
private:
    int minutes;
    int seconds;
    
    void normalize(); // чтобы секунды не превышали 60

public:
    Time();
    Time(int m, int s);
    Time(const Time&);

    Time operator=(const Time&);
    bool operator==(const Time&) const;
    Time operator+(const Time&) const;

    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, const Time& t);

    friend std::fstream& operator>>(std::fstream& in, Time& t);
    friend std::fstream& operator<<(std::fstream& out, const Time& t);
};
