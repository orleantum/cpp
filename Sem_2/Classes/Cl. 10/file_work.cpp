#include "file_work.h"
#include <fstream>

int make_file(const char* f_name) {
    std::fstream stream(f_name, std::ios::out | std::ios::trunc);
    if (!stream) return -1;
    int n;
    std::cout << "N? "; std::cin >> n;
    Time t;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        stream << t;
    }
    stream.close();
    return n;
}

int print_file(const char* f_name) {
    std::fstream stream(f_name, std::ios::in);
    if (!stream) return -1;
    Time t;
    int i = 0;
    while (stream >> t) {
        std::cout << i + 1 << ") " << t << "\n";
        i++;
    }
    stream.close();
    return i;
}

int del_equal(const char* f_name, Time key) {
    std::fstream in(f_name, std::ios::in);
    std::fstream out("temp", std::ios::out);
    if (!in || !out) return -1;

    Time t;
    int count = 0;
    while (in >> t) {
        if (!(t == key)) out << t;
        else count++;
    }

    in.close(); out.close();
    remove(f_name);
    rename("temp", f_name);
    return count;
}

int update_equal(const char* f_name, Time key) {
    std::fstream in(f_name, std::ios::in);
    std::fstream out("temp", std::ios::out);
    if (!in || !out) return -1;

    Time t;
    int count = 0;
    Time delta(1, 30); // +1 минута 30 секунд

    while (in >> t) {
        if (t == key) {
            out << (t + delta);
            count++;
        } else {
            out << t;
        }
    }

    in.close(); out.close();
    remove(f_name);
    rename("temp", f_name);
    return count;
}

int add_after(const char* f_name, int pos, Time* times, int k) {
    std::fstream in(f_name, std::ios::in);
    std::fstream out("temp", std::ios::out);
    if (!in || !out) return -1;

    Time t;
    int i = 0;

    while (in >> t) {
        out << t;
        i++;
        if (i == pos) {
            for (int j = 0; j < k; j++) {
                out << times[j];
            }
        }
    }

    in.close(); out.close();
    remove(f_name);
    rename("temp", f_name);
    return k;
}
