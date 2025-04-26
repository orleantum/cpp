#include <iostream>
#include <string>

using namespace std;

class Student
{
    // атрибуты
    string name;
    string group;
    float avg_score;
    
public:
    Student(); // конструктор без параметров
    Student(string, string, float); // конструктор с параметрами
    Student(const Student&); // конструктор копирования
    ~Student(); // деконструктор
    string get_name(); // селектор
    void set_name(string); // модификатор
    string get_group(); // селектор
    void set_group(string); // модификатор
    double get_avg_score(); // селектор
    void set_avg_score(float); // модификатор
    void show(); // просмотров атрибутов
};
