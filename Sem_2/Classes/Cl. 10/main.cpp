#include "Time.h"
#include "file_work.h"
#include <iostream>

int main() {
    char filename[30];
    int command;
    do {
        std::cout << "\n1. Make file\n2. Print file\n3. Delete equal to value\n";
        std::cout << "4. Add 1m30s to matching\n5. Add K after position\n0. Exit\n";
        std::cin >> command;
        switch (command) {
            case 1:
                std::cout << "Filename? "; std::cin >> filename;
                make_file(filename);
                break;
            case 2:
                std::cout << "Filename? "; std::cin >> filename;
                print_file(filename);
                break;
            case 3: {
                std::cout << "Filename? "; std::cin >> filename;
                Time key; std::cin >> key;
                int del = del_equal(filename, key);
                std::cout << "Deleted: " << del << "\n";
                break;
            }
            case 4: {
                std::cout << "Filename? "; std::cin >> filename;
                Time key; std::cin >> key;
                int changed = update_equal(filename, key);
                std::cout << "Updated: " << changed << "\n";
                break;
            }
            case 5: {
                std::cout << "Filename? "; std::cin >> filename;
                int pos, k;
                std::cout << "After which element? "; std::cin >> pos;
                std::cout << "How many records to insert? "; std::cin >> k;
                Time* arr = new Time[k];
                for (int i = 0; i < k; i++) std::cin >> arr[i];
                add_after(filename, pos, arr, k);
                delete[] arr;
                break;
            }
        }
    } while (command != 0);
    return 0;
}
