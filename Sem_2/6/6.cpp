#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	string str = "C?a.td, t,A.C,";
	int str_size = size(str);
	cout << "str: " << str << endl;
	cout << "str_size: " << str_size << endl;

	for (int i = 0; i < str_size; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
		if (str[i] == '.'
			or str[i] == '!'
			or str[i] == '?'
			or str[i] == ','
			or str[i] == ' ') {
			str.erase(i, 1);
			i--;
			str_size--;
		}
	}

	cout << "modified str: " << str << endl;
	int max = str_size - 1;
	bool flag = true;

	for (int i = 0; i < str_size / 2 + 1; i++) {
		string str_left = str.substr(i, 1);
		string str_right = str.substr(max, 1);

		if (str_left != str_right) {
			flag = false;
			break;
		}
		max--;
	}

	if (flag) {
		cout << "Palindrome" << endl;
	}
	else {
		cout << "Not palindrome" << endl;
	}
	
	return 0;
}
