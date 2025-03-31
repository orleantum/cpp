#include <iostream>

using namespace std;


void arr(int j, char array[][15]){
    cout << '(';
    
    for (int i = 0; i < 15; i++){
        if (i == 14){
            cout << ')';
        }
        else if (array[j][i] == '0'){
            cout << ',';
        }
        else{
            cout << array[j][i];
        }
    }
}


int main() {
    const int rows = 3;
    const int cols = 15;
    char array[rows][cols] = { {'1', '2', '3', '0', '2', '3', '4', '0', '2', '3', '0', '3', '4', '5', '0'},
        {'2', '3', '4', '4', '5', '0', '2', '3', '4', '5', '6', '7', '0', '1', '0'},
        {'2', '3', '4', '4', '5', '5', '6', '7', '7', '6', '7', '0', '4', '5', '0'}};
    for (int index = 0; index < rows; index++){
        arr(index, array);
    }
    cout << endl;
    return 0;
}
