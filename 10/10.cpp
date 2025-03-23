#include <iostream>

using namespace std;

int main() {
    int size;
    int nsize;
    int dn;
    int nn;

    cout << "Type array size: ";
    cin >> size;

    int* arr = new int[size];

    // Заполнение массива
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << i << "\t";
        cout << arr[i] << "\t";
        cout << arr + i << endl;
    }

    cout << endl << "Type index of element to delete: ";
    cin >> dn;

    // Проверка
    if (dn < 0 || dn >= size) {
        cout << "Invalid index!" << endl;
        delete[] arr;
        return 1;
    }

    // Удаление элемента
    for (int i = dn; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    for (int i = 0; i < size; i++)
    {
        cout << i << "\t";
        cout << arr[i] << "\t";
        cout << arr + i << endl;
    }


    cout << endl << "Type index of element to add: ";
    cin >> nn;

    // Если индекс выходит за пределы массива
    if (nn >= size + 1) {
        int* newArr = new int[nn + 1];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        for (int i = size; i < nn; i++)
        {
            newArr[i] = 0;
        }

        size = nn;

        newArr[size - 1] = rand() % 10;

        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            cout << newArr[i] << "\t";
            cout << newArr + i << endl;
        }

        delete[] newArr;
    }
    else {
        int* newArr = new int[size];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        newArr[nn] = rand() % 10;

        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            cout << newArr[i] << "\t";
            cout << newArr + i << endl;
        }

        delete[] newArr;
    }

    delete[] arr;

    return 0;
}