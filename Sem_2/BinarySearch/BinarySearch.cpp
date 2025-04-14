#include <iostream>

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

int binarySearchRec(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) return mid;

        
        if (arr[mid] < x) { low = mid + 1; }
        else { high = mid - 1; }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) return mid;
        
        // если середина больше ключа, ищем в левой (меньшей) стороне массива
        if (arr[mid] > x) return binarySearchRec(arr, low, mid-1 , x);
        
        // если середина меньше ключа, ищем ключ в правой (большей стороне массива)
        return binarySearchRec(arr, mid+1, high, x);
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
    
    int res = binarySearch(arr, 0, size - 1, x);
    if (res == -1) std::cout << "Элемент " << x << " не найден." << std::endl;
    else std::cout << "Элемент " << x << " найден по индексу " << res << std::endl;
    return 0;
}
