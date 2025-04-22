#include <iostream>

using namespace std;

int* bucketSort(int arr[], int n)
{
    // для наглядности запишем количество вёдер
    // и их размер прямо здесь, хотя их стоит вынести вне функции
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 10;

    int buckets[BUCKET_NUM][BUCKET_SIZE];

    int bucketSizes[BUCKET_NUM] = { 0 };

    // раскидываем элементы массива по вёдрам
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / BUCKET_NUM;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    
    // сортируем каждое ведро
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        // берём сортировку вставками или любую другую
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j-1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = tmp;
        }
    }

    // складываем элемены в исходный массив
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
    
    return arr;
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
    
    bucketSort(arr, size);
        
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
        
    cout << endl;
    
    return 0;
}
