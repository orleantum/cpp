#include "Dialog.h"
#include <iostream>
#include <sstream>

Dialog::Dialog() : running(true) {}

void Dialog::Execute() {
    std::string command;
    while (running) {
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);

        if (command.empty()) continue;

        if (command[0] == 'q') {
            running = false;
        } else if (command[0] == 'm') {
            int n;
            std::istringstream(command.substr(1)) >> n;
            std::cout << "Группа создана (макс. " << n << ")\n";
            // ничего не делаем, размер у нас фиксирован в Vector
        } else if (command[0] == '+') {
            Student* s = new Student();
            s->Input();
            if (!group.Add(s)) {
                delete s; // Освобождаем память, если не удалось добавить
            }
        } else if (command[0] == '-') {
            group.RemoveLast();
        } else if (command[0] == 's') {
            group.Show();
        } else if (command[0] == '?') {
            int index;
            std::istringstream(command.substr(1)) >> index;
            Object* obj = group.Get(index);
            if (obj) obj->Show();
            else std::cout << "Неверный индекс.\n";
        } else {
            std::cout << "Неизвестная команда.\n";
        }
    }
}
