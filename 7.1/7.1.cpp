#include <iostream>

using namespace std;

int sum(int n, int array[]) {
    int s = 0;
    
    for (int i = 0; i < n; i++){
        s += array[i];
    }
    
    return s;
}


void sum(int n, float array[n][2]) {
    float a = 0;
    float b = 0;
    for (int i = 0; i < n; i++){
        a += array[i][0];
        b += array[i][1];
    }
    
    cout << "z = " << a << " + " << b << "i" << endl;
}


int main() {
    int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    float arr2[10][2] = { {2, -1}, {3, 6}, {4, -17}, {6, -9}, {8, 6}, {5, -1}, {4, -8}, {2, -1}, {2, -1}, {2, -1} };
    int arr1Length = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Length = sizeof(arr2) / sizeof(arr2[0]);
    int a = sum(arr1Length, arr1);
    sum(arr2Length, arr2);
    
    cout << a << endl;
    return 0;
}
