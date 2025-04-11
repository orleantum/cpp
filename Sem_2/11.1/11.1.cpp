#include <iostream>
#include <fstream>

using namespace std;

// Однонаправленный список
struct SingleList {
    int data;
    SingleList* next;
};

// Функция для печати списка
void printList(SingleList* head) {
    int counter = 0;
    while (head) {
        cout << "[" << counter << "]" << head->data << " -> ";
        head = head->next;
        counter++;
    }
    cout << "nullptr\n";
}

// Функция заполнения списка
SingleList* createList(int n)
{
    SingleList* start = nullptr;
    SingleList* prev = nullptr;

    for (int i = 0; i < n; ++i)
    {
        SingleList* cur = new SingleList;
        cur->data = rand() % 11;
        cur->next = nullptr;

        if (i == 0)
        {
            start = cur;  // первый элемент становится началом списка
        }
        else
        {
            prev->next = cur;  // предыдущий указывает на текущий
        }

        prev = cur;  // текущий становится предыдущим для следующей итерации
    }

    return start;
}

// Функция для восстановления списка из файла
SingleList* RestoreList(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Can't open file for reading." << endl;
        return nullptr;
    }

    SingleList* head = nullptr;
    SingleList* tail = nullptr;
    int value;

    while (file >> value) {
        SingleList* newNode = new SingleList{ value, nullptr };

        if (!head) {
            head = newNode;     // первый элемент
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;     // передвигаем "хвост"
        }
    }

    file.close();
    return head;
}

// Функция удаления элемента по индексу
void deleteNodeByIndex(SingleList*& head, int index) {
    if (head == nullptr || index < 0) return;

    // Удаляем голову
    if (index == 0) {
        SingleList* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    SingleList* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == nullptr) return; // индекс вне диапазона
        current = current->next;
    }

    // current указывает на элемент перед тем, что нужно удалить
    if (current->next == nullptr) return; // нет элемента по индексу

    SingleList* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Функция добавления элемента по индексу
void insertNodeByIndex(SingleList*& head, int index, int value) {
    if (index < 0) return;

    SingleList* newNode = new SingleList;
    newNode->data = value;
    newNode->next = nullptr;

    // Вставка в начало
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    SingleList* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            delete newNode; // индекс вне списка
            return;
        }
        current = current->next;
    }

    if (current == nullptr) {
        delete newNode; // индекс за пределами
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Функция удаления списка 
void deleteList(SingleList* head) {
    while (head != nullptr) {
        SingleList* temp = head;    // сохраняем текущий узел
        head = head->next;          // переходим к следующему
        delete temp;                // удаляем текущий
    }
    cout << "The list is empty\n";
}

// Функция записи в файл
void writeList(SingleList* head) {
    string path = "11.1.txt";
    ofstream file_1(path);  // можно открыть файл так, проще

    if (file_1.is_open()) {
        cout << "11.1.txt opened for writing." << endl;

        SingleList* current = head;
        while (current != nullptr) {
            file_1 << current->data << endl;
            current = current->next;
        }
    }
    else {
        cout << "Can't open 11.1.txt";
    }

    file_1.close();
}

int main() {
    // Создание списка
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    SingleList* myList = createList(n);

    cout << "Contents of the list: ";
    printList(myList); // вывод

    // Добавление элемента
    cout << "Enter the index to insert: ";
    int index;
    cin >> index;

    cout << "Enter the value of the new element: ";
    int value;
    cin >> value;

    insertNodeByIndex(myList, index, value);

    cout << "List after insert: ";
    printList(myList); // вывод

    // Удаление элемента
    cout << "Enter the ID of the element to be removed: ";
    cin >> index;

    deleteNodeByIndex(myList, index);

    cout << "List after deletion: ";
    printList(myList); // вывод

    // Запись списка в файл
    writeList(myList);

    // Удаление списка
    deleteList(myList);

    // Восстановление списка
    SingleList* restoredList = RestoreList("11.1.txt");

    cout << "Restored list from file: ";
    printList(restoredList);

    deleteList(restoredList);

    return 0;
}
