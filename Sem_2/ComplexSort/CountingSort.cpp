#include <iostream>

using namespace std;

int* countingSort(int arr[], int size)
{
    int* output = new int[size];
    int* count;

    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
    }

    count = new int[max+1];
    for (int i = 0; i <= max; ++i) { count[i] = 0; }

    // выполняем подсчёт уникальных значений элементов
    for (int i = 0; i < size; i++) { count[arr[i]]++; }

    // вычисляем префиксные суммы
    for (int i = 1; i <= max; ++i)
    {
        count[i] += count[i-1];
    }

    // заполняем выходной массив
    for (int i = size-1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // опционально — модифицируем исходный массив
    for (int i = 0; i < size; i++) { arr[i] = output[i]; }

    delete[] count;
    delete[] output;

    return arr;
}

int main()
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int arr[size];
        
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i];
    }
        
    cout << endl;

    countingSort(arr, size);
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    
    cout << endl;

    return 0;
}
