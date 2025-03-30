#include <iostream>
#include <fstream>

using namespace std;

int main() {
//    string path1 = "/Users/ilya/Documents/PSTU/С++/Sem_2/9/F1.txt";
//    string path2 = "/Users/ilya/Documents/PSTU/С++/Sem_2/9/F2.txt";
    string path1 = "F1.txt";
    string path2 = "F2.txt";
    
    
    // Открытие первого файла для записи
    ofstream file_1;
    file_1.open(path1);
    if (file_1.is_open())
    {
        cout << "F1 opened for writing." << endl;
        file_1 <<
        "How many problems get solved?" << endl <<
        "Am I a product of things that I saw?" << endl <<
        "How many problems get solved?" << endl <<
        "Am I a product of things in my songs?" << endl <<
        "How many problems get solved?" << endl <<
        "Am I a product of all of my flaws?" << endl <<
        "How many problems get solved" <<endl <<
        "If we don't get involved?" << endl <<
        "How many problems get solved?" << endl <<
        "Am I a product of things that I saw?" << endl <<
        "How many problems get solved?" << endl <<
        "Am I a product of things in my songs?" << endl <<
        "How many problems get solved?" << endl <<
        "Am I a product of all of my flaws?" << endl <<
        "How many problems get solved" << endl <<
        "If we don't get involved?";
    }
    else
    {
        cout << "Can't open F1.";
    }
    file_1.close();
    
    
    // Открытие первого файла для чтения
    ifstream file_2;
    file_2.open(path1);
    
    string str1, str2;
    
    if (file_2.is_open())
    {
        cout << "F1 opened for reading." << endl;
        
        int counter = 0;
        while (!file_2.eof())
        {
            str1 = "";
            if (counter % 2 == 0)
            {
                getline(file_2, str1);
                str2 += str1 + "\n";
            }
            else
            {
                getline(file_2, str1);
            }
            
            counter++;
        }
    }
    else
    {
        cout << "Can't open F1.";
    }
    file_2.close();
    
    
    // Открытие второго файла для записи
    ofstream file_3;
    file_3.open(path2);
    if (file_3.is_open())
    {
        cout << "F2 opened for writing." << endl;
        file_3 << str2;
    }
    else
    {
        cout << "Can't open F2.";
    }
    file_3.close();
    
    
    // Подсчёт размера файлов
    ifstream f1(path1, ios::binary | ios::ate);
    ifstream f2(path2, ios::binary | ios::ate);
    
    if (f1.is_open() && f2.is_open()) {
        streampos size1 = f1.tellg();
        streampos size2 = f2.tellg();
        
        cout << "Size of F1.txt: " << size1 << " bytes" << endl;
        cout << "Size of F2.txt: " << size2 << " bytes" << endl;
    } else {
        cout << "Can't open files to check size." << endl;
    }
    f1.close();
    f2.close();
    
    return 0;
}
