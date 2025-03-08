#include <iostream>

using namespace std;

int main() {
    int const size = 10;
    int array[size];
    int range_min, range_max, replace;
    range_min = 2;
    range_max = 10000;
    
    
    for (int i = 0; i < size; i++) {
        array[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << array[i] << " ";
    }
    
    
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j > 1; j--){
            if (array[j] < array[j - 1]){
                replace = array[j - 1];
                array[j - 1] = array[j];
                array[j] = replace;
            }
        }
    }
    
    cout << endl;
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}
