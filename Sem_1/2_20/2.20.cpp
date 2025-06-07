#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, found, tmp;
	bool flag = false;
	cin >> n >> found;
	for (int i = 1; i <= n; i++)
	{
		tmp = sin(n + (i/n));
		if (found==tmp)
		{
			flag = true;
		}
	}
	if (flag) 
	{
		cout << "Элемент найден" << endl;
	}
        else
        {
		cout << "Элемент не найден" << endl;
        }
	return 0;
}