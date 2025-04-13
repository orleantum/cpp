#include <iostream>

int search(int arr[], int arrLength, int x)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == x) return i;
	}

	return -1;
}


int main()
{
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
	
	int x;
	std::cout << "Enter the number to found: ";
	std::cin >> x;
	int res = search(arr, size, x);

	if (res == -1) std::cout << "Element " << x << " is not found.\n";
	else std::cout << "Element " << x << " found on index " << res << std::endl;
	return 0;
}