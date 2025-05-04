#include <iostream>
#include "Vector.h"

using namespace std;

void menu() {
    cout << "\n==== MENU ====\n";
    cout << "1. Input vector values\n";
    cout << "2. Display vector\n";
    cout << "3. Get vector size\n";
    cout << "4. Modify an element by index\n";
    cout << "5. Add a number to all elements\n";
    cout << "6. Iterate through vector using iterator\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
}

int main() {
    int size, defaultValue;
    cout << "Enter vector size: ";
    cin >> size;
    cout << "Enter default value: ";
    cin >> defaultValue;

    Vector vec(size, defaultValue);

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter " << vec() << " elements: ";
                cin >> vec;
                break;

            case 2:
                cout << "Vector: " << vec << endl;
                break;

            case 3:
                cout << "Vector size: " << vec() << endl;
                break;

            case 4: {
                int index, value;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                vec[index] = value;
                break;
            }

            case 5: {
                int add;
                cout << "Enter number to add: ";
                cin >> add;
                vec = vec + add;
                cout << "Updated vector: " << vec << endl;
                break;
            }

            case 6: {
                cout << "Vector elements: ";
                for (Iterator it = vec.first(); it != vec.last(); ++it)
                    cout << *it << " ";
                cout << endl;
                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
