#include <iostream>
#include <string>
#include <ctime>

int collisions = 0;

struct Person {
    std::string name;
    std::string groupe;
    std::string rating; // rating of birth
    
    Person() {
        name = "NULL";
        groupe = "NULL";
        rating = "NULL";
    }
};

struct hashTable {
    Person* arr;
    hashTable(int size) {
        arr = new Person[size];
    }
    
    void insert(Person p, int size);
    Person pop(std::string rating, int size);
    void search(std::string rating, int size);
};

int hash(std::string str, int size)
{
    unsigned long hash = 0;
    for (char ch : str) {
        hash = (hash * 31 + ch) % size; // простое и устойчивое хеширование
    }
    return hash % size;
}

void hashTable::insert(Person p, int size)
{
    int idx = hash(p.name, size);
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

Person hashTable::pop(std::string name, int size)
{
    int idx = hash(name, size);
    int hash = idx;
    if (arr[idx].name == name)
    {
        Person tmp = arr[idx];
        arr[idx] = Person();
        return tmp;
    }
    while(idx < size)
    {
        if (arr[idx].name == name)
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
            if (arr[idx].name == name)
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

void hashTable::search(std::string name, int size)
{
    int idx = hash(name, size);
    int startIdx = idx;
    
    // Поиск в пределах таблицы
    while (arr[idx].name != "NULL" && arr[idx].name != name) {
        idx = (idx + 1) % size;  // Окружной поиск
        if (idx == startIdx) {
            std::cout << "Person with full name " << name << " is not found" << std::endl;
            return;
        }
    }

    // Если элемент найден
    if (arr[idx].name == name) {
        std::cout << "Person with full name " << name << " if found on index " << idx << std::endl;
    } else {
        std::cout << "Person with full name " << name << " is not found" << std::endl;
    }
}


void displayPerson(Person p)
{
    std::cout << "===" << std::endl;
    std::cout << "Full name: " << p.name << std::endl;
    std::cout << "Groupe: " << p.groupe << std::endl;
    std::cout << "Rating: " << p.rating << std::endl;
    std::cout << "===" << std::endl;
}

void displayHashTable(hashTable* table, int size)
{
    int filled = 0, empty = 0;
    for (int i = 0; i < size; i++)
    {
        if (table->arr[i].name != "NULL")
        {
            displayPerson(table->arr[i]);
            filled++;
        }
        else
        {
            empty++;
        }
    }
    std::cout << "Filled buckets: " << filled << std::endl;
    std::cout << "Empty buckets: " << empty << std::endl;
}



int main()
{
    int size;
    std::cout << "Type size of the Hash Table: ";
    std::cin >> size;
    std::cin.ignore();

    hashTable table(size);
    std::string word;

    while (true)
    {
        std::cout << "\nChoose action:\n1 - Add\n0 - Delete\n2 - Search\nType \"exit\" to exit\n> ";
        std::getline(std::cin, word);

        if (word == "exit") break;

        if (word == "1") {
            Person p;
            std::cout << "Type FullName: ";
            std::getline(std::cin, p.name);
            
            std::cout << "Type Groupe: ";
            std::getline(std::cin, p.groupe);
            
            std::cout << "Type Rating: ";
            std::getline(std::cin, p.rating);
            
            table.insert(p, size);
        }
        else if (word == "0") {
            std::string name;
            std::cout << "Type FullName to delete: ";
            std::getline(std::cin, name);
            
            Person removed = table.pop(name, size);
            std::cout << "Deleted person:\n";
            displayPerson(removed);
        }
        else if (word == "2") {
            std::string name;
            std::cout << "Type FullName to search: ";
            std::getline(std::cin, name);
            
            table.search(name, size);
        }
        else {
            std::cout << "Wrong command. Use 1 (add), 0 (delete), 2 (search), or \"exit\".\n";
        }
    }

    std::cout << "\nFinal table:\n";
    displayHashTable(&table, size);
    std::cout << "\nCollisions: " << collisions << std::endl;

    return 0;
}

