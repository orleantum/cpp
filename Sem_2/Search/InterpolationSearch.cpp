#include <iostream>

using namespace std;

void selectionSort(int size, int array[])
{
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

    std::cout << std::endl;

    std::cout << "Sorted array.\n";
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "]" << array[i] << " ";
    }
    
    std::cout << std::endl;
}

// Рекурсивный вариант
int interpolationSearchRec(int arr[], int low, int high, int x)
{
    while (high >= low && x >= arr[low] && x <= arr[high])
    {
        int pos = low + ( ( (x - arr[low]) * (high-low) ) / (arr[high] - arr[low]) );

        if (arr[pos] == x) return pos;
        
        if (arr[pos] > x) return interpolationSearchRec(arr, low, pos-1, x);
        
        if (arr[pos] < x) return interpolationSearchRec(arr, pos+1, high, x);
    }
    return -1;
}

int main()
{
    // массив должен быть отсортирован
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 11;
        std::cout << "[" << i << "]" << arr[i] << " ";
    }
    std::cout << std::endl;
    
    selectionSort(size, arr);
    
    int x;
    std::cout << "Enter the number to found: ";
    std::cin >> x;
    
    int res = interpolationSearchRec(arr, 0, size-1, x);
    if (res == -1) cout << "Элемент " << x << " не найден." << endl;
    else cout << "Элемент " << x << " найден по индексу " << res << endl;
    return 0;
}
