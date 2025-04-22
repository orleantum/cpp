#include <iostream>

using namespace std;

void shellSort(int arr[], int n)
{
    for (int h = n/2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            {
                for (j = i; j >= h && arr[j-h] > tmp; j-=h)
                    arr[j] = arr[j - h];
            }
            //альтернативно
//            for (int j = i; j >= h; j-=h)
//            {
//                if (tmp < arr[j - h])
//                {
//                    arr[j] = arr[j - h];
//                }
//                else break;
//            }
            arr[j] = tmp;
        }
    }
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
            
    shellSort(arr, size - 1);
            
    for (int i = 0; i < size; i++)
    {
    cout << arr[i];
    }
            
    cout << endl;
    
    return 0;
}
