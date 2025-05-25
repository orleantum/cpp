#pragma once
#include <string>
#include <iostream>

using namespace std;

class error // Класс ошибка
{
    string str;
public:
    // Конструктор, инициирует атрибут str сообщением об ошибке
    error(string s) {
        str = s;
    }
    
    void what() {
        cout << str << endl;
    } // Выводит значение атрибута str
};
