#include <iostream>
#include <string>
#include <ctime>

int collisions = 0;

struct Person {
    std::string name;
    std::string phone;
    std::string date; // date of birth
    
    Person() {
        name = "NULL";
        phone = "NULL";
        date = "NULL";
    }
};

struct hashTable {
    Person* arr;
    hashTable(int size) {
        arr = new Person[size];
    }
    
    void insert(Person p, int size);
    Person pop(std::string date, int size);
    void search(std::string date, int size);
};

int hash(std::string str, int size)
{
    double f = 0.1337 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
    double g = (f - int(f)) * size;
    return int(g);
}

void hashTable::insert(Person p, int size)
{
    int idx = hash(p.date, size);
    int startIdx = idx;
    if (arr[idx].name == "NULL")
    {
        arr[idx] = p;
        return;
    }
    while(idx < size)
    {
        if (arr[idx].name == "NULL")
        {
            arr[idx] = p;
            return;
        }
        idx++;
        collisions++;
    }
    if (idx >= size)
    {
        idx = 0;
        collisions++;
        while (idx < startIdx)
        {
            if (arr[idx].name == "NULL")
            {
                arr[idx] = p;
                return;
            }
            idx++;
            collisions++;
        }
    }
}

Person hashTable::pop(std::string date, int size)
{
    int idx = hash(date, size);
    int hash = idx;
    if (arr[idx].date == date)
    {
        Person tmp = arr[idx];
        arr[idx] = Person();
        return tmp;
    }
    while(idx < size)
    {
        if (arr[idx].date == date)
        {
            Person tmp = arr[idx];
            arr[idx] = Person();
            return tmp;
        }
        idx++;
    }
    if (idx >= size)
    {
        idx = 0;
        while (idx < hash)
        {
            if (arr[idx].date == date)
            {
                Person tmp = arr[idx];
                arr[idx] = Person();
                return tmp;
            }
            idx++;
        }
    }
    
    return Person();
}

void hashTable::search(std::string date, int size)
{
    int idx = hash(date, size);
    int hash = idx;
    while(arr[idx].date != date && idx < size) { idx++; }
    if (idx < size)
    {
        std::cout << "Человек с датой рождения " << date << " найден по индексу " << idx << std::endl;
        return;
    }
    idx = 0;
    while(arr[idx].date != date && idx < hash) { idx++; }
    if (idx < hash)
    {
        std::cout << "Человек с датой рождения " << date << " найден по индексу " << idx << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "Человек с датой рождения " << date << " не найден";
    return;
}

void displayPerson(Person p)
{
    std::cout << "===" << std::endl;
    std::cout << "ФИО: " << p.name << std::endl;
    std::cout << "Телефон: " << p.phone << std::endl;
    std::cout << "Дата рождения: " << p.date << std::endl;
    std::cout << "===" << std::endl;
}

void displayHashTable(hashTable* table, int size)
{
    for (int i = 0; i < size; i++) displayPerson(table->arr[i]);
}



int main()
{
    int size = 10;
    hashTable table(size);

    Person p1;
    p1.name = "Иванов Иван";
    p1.phone = "799999999999";
    p1.date = "01.01.2000";
    table.insert(p1, size);

    Person p2;
    p2.name = "Петров Пётр";
    p2.phone = "788888888888";
    p2.date = "02.02.2002";
    table.insert(p2, size);

    Person p3;
    p3.name = "Сидоров Сидр";
    p3.phone = "777777777777";
    p3.date = "03.03.2003";
    table.insert(p3, size);

    std::cout << "Таблица после вставки:\n";
    displayHashTable(&table, size);

    std::cout << "\nПоиск:\n";
    table.search("02.02.2002", size);
    table.search("04.04.2004", size);

    std::cout << "\nУдаление:\n";
    Person removed = table.pop("02.02.2002", size);
    displayPerson(removed);

    std::cout << "\nТаблица после удаления:\n";
    displayHashTable(&table, size);

    std::cout << "\nКоллизии: " << collisions << std::endl;

    return 0;
}
