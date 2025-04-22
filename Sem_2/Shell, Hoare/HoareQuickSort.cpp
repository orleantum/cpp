#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;
    for (int i = low+1; i <= high; i++)
    {
        if (arr[i] < pivot) { num++; }
    }
    int pos = low + num; // если нашли значение в массиве, которое меньше pivot на 0 индексе, то запоминаем эту позицию
    swap(arr[pos], arr[low]); // помещаем сразу самое маленькое найденное значение на 0 индекс, а pivot — на найденную позицию
    int i = low, j = high;
    while (i < pos && j > pos)
    {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if (i < pos && j > pos) swap(arr[i++], arr[j--]);
    }
    return pos;
}

/* Быстрая сортировка по Хоару */
void hoareQuickSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pI = partition(arr, low, high);
    // после этого разделения arr[pI] уже будет в правильном месте в исходном массиве
    // сортируем часть элементов до pivot
    hoareQuickSort(arr, low, pI-1);
    // сортируем часть элементов после pivot
    hoareQuickSort(arr, pI+1, high);
}

int main() {
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
                
    hoareQuickSort(arr, 0, size - 1);
    
    for (int i = 0; i < size; i++)
    {
    cout << arr[i];
    }
                
    cout << endl;
    
    return 0;
}
