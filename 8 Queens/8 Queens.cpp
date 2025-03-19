#include <iostream>

using namespace std;


int randomize(int range_min, int range_max)
{
    int a = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return a;
}


int main() {
    const int rc = 8;
    int table[rc][rc];
    int range_min, range_max, a;
    range_min = 0;
    range_max = 9;
    
    for (int i = 0; i < rc; i++){
        for (int j = 0; j < rc; j++){
            table[i][j] = 0;
        }
    }
    
    for (int i = 0; i < rc; i++){
        a = randomize(range_min, range_max);
        table[i][a] = 1;
    }
    
    for (int i = 0; i < rc; i++){
        for (int j = 0; j < rc; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
