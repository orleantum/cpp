#include <iostream>

using namespace std;

int main()
{
    int const size = 14;
    int array[size];
    int range_min, range_max;
    range_min = 2;
    range_max = 10000;


    for (int i = 0; i < size; i++) {
        array[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << array[i] << " ";
    }

    int replace;
    int number;

    for (int i = 0; i < size; i++) {
        replace = array[i];
        number = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < replace) {
                replace = array[j];
                number = j;
            }
        }
        array[number] = array[i];
        array[i] = replace;
    }

    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}