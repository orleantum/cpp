#include "Time.h"

Time::Time() : minutes(0), seconds(0) {}

Time::Time(int m, int s) : minutes(m), seconds(s) {
    normalize();
}

Time::Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}

Time Time::operator=(const Time& t) {
    if (this == &t) return *this;
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

bool Time::operator==(const Time& t) const {
    return minutes == t.minutes && seconds == t.seconds;
}

Time Time::operator+(const Time& t) const {
    return Time(minutes + t.minutes, seconds + t.seconds);
}

void Time::normalize() {
    minutes += seconds / 60;
    seconds = seconds % 60;
}

std::istream& operator>>(std::istream& in, Time& t) {
    std::cout << "Minutes? ";
    in >> t.minutes;
    std::cout << "Seconds? ";
    in >> t.seconds;
    t.normalize();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}

std::fstream& operator>>(std::fstream& in, Time& t) {
    in >> t.minutes >> t.seconds;
    t.normalize();
    return in;
}

std::fstream& operator<<(std::fstream& out, const Time& t) {
    out << t.minutes << " " << t.seconds << "\n";
    return out;
}
