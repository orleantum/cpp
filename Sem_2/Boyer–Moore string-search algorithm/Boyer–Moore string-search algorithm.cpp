#include <iostream>
using namespace std;
const int CHAR_NUM = 256;
void calcCharTable(string pat, int size, int charTable[CHAR_NUM])
{
    for (int i = 0; i < CHAR_NUM; i++)
    {
        charTable[i] = -1;
    }
// заполняем таблицу индексом последнего вхождения этого символа в подстроке
    for (int i = 0; i < size; i++)
    {
        charTable[(int)pat[i]] = i;
    }
}

void boyerMooreSearch(string str, string pat)
{
    int strSize = str.size();
    int patSize = pat.size();
    int shiftTable[CHAR_NUM];
    calcCharTable(pat, patSize, shiftTable);
    int shift = 0;
    while (shift <= (strSize - patSize))
    {
        int j = patSize - 1;
        // суффиксный поиск
        while (j >= 0 && pat[j] == str[shift+j])
        { j--; }
        if (j < 0)
        {
            cout << "Подстрока найдена на позиции: " << shift << endl;
            if (shift+patSize < strSize)
            {
                shift += patSize -
                shiftTable[(int)str[shift+patSize]];
            }
        }
        else
        {
            shift += max(1, j - shiftTable[(int)str[shift+j]]);
        }
    }
}

int main()
{
    string inputStr, searchStr;
    cout << "Enter string: ";
    cin >> inputStr;
    cout << "Enter symbols to find: ";
    cin >> searchStr;
    
    boyerMooreSearch(inputStr, searchStr);
    
    return 0;
}
