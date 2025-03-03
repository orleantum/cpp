#include <iostream>

using namespace std;


int main()
{
    int const size = 40;
    int const new_size = 100;
    int array[size];
    int new_array[new_size];

    int range_min, range_max, a, k;
    range_min = 2;
    range_max = 10000;


    for (size_t i = 0; i < size; i++) {
        array[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << array[i] << " ";
    }

    cout << endl << "Enter K: ";
    cin >> k;

    for (int i = k; i < size; i++) {
        array[i] = array[i + 1];
    }

    int counter = 0;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] % 2 == 0) {
            counter++;
            new_array[i + counter - 1] = array[i];
            new_array[i + counter] = 0;
        }
        else {
            new_array[i + counter] = array[i];
        }
    }

    for (int i = 0; i < size + counter; i++) {
        cout << new_array[i] << " ";
    }

    return 0;
}