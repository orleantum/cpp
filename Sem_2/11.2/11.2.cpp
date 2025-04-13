#include <iostream>
#include <fstream>

using namespace std;

struct DoubleList {
    int data;
    DoubleList* next;
    DoubleList* prev;
};

void printList(DoubleList* head) {
    int counter = 0;
    while (head) {
        cout << "[" << counter << "]" << head->data << " <-> ";
        head = head->next;
        counter++;
    }
    cout << "nullptr\n";
}

DoubleList* createList(int n) {
    DoubleList* head = nullptr;
    DoubleList* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        DoubleList* node = new DoubleList;
        node->data = rand() % 11;
        node->next = nullptr;
        node->prev = tail;

        if (!head)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    return head;
}

DoubleList* RestoreList(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Can't open file for reading." << endl;
        return nullptr;
    }

    DoubleList* head = nullptr;
    DoubleList* tail = nullptr;
    int value;

    while (file >> value) {
        DoubleList* node = new DoubleList{ value, nullptr, tail };
        if (!head)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    file.close();
    return head;
}

void deleteNodeByIndex(DoubleList*& head, int index) {
    if (!head || index < 0) return;

    DoubleList* current = head;
    for (int i = 0; i < index && current; ++i)
        current = current->next;

    if (!current) return;

    if (current->prev)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next)
        current->next->prev = current->prev;

    delete current;
}

void insertNodeByIndex(DoubleList*& head, int index, int value) {
    DoubleList* newNode = new DoubleList{ value, nullptr, nullptr };

    if (index == 0) {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return;
    }

    DoubleList* current = head;
    for (int i = 0; i < index - 1 && current; ++i)
        current = current->next;

    if (!current) {
        delete newNode;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next)
        current->next->prev = newNode;

    current->next = newNode;
}

void deleteList(DoubleList* head) {
    while (head) {
        DoubleList* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "The list is empty\n";
}

void writeList(DoubleList* head) {
    ofstream file("11.2.txt");

    if (!file.is_open()) {
        cout << "Can't open file for writing.\n";
        return;
    }

    while (head) {
        file << head->data << endl;
        head = head->next;
    }

    file.close();
    cout << "List written to file.\n";
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    DoubleList* myList = createList(n);

    cout << "Contents of the list: ";
    printList(myList);

    // Вставка
    int index, value;
    cout << "Enter the index to insert: ";
    cin >> index;
    cout << "Enter the value of the new element: ";
    cin >> value;

    insertNodeByIndex(myList, index, value);
    cout << "List after insert: ";
    printList(myList);

    // Удаление
    cout << "Enter the ID of the element to be removed: ";
    cin >> index;

    deleteNodeByIndex(myList, index);
    cout << "List after deletion: ";
    printList(myList);

    // Запись в файл
    writeList(myList);

    // Очистка
    deleteList(myList);

    // Восстановление
    DoubleList* restoredList = RestoreList("11.2.txt");
    cout << "Restored list from file: ";
    printList(restoredList);

    deleteList(restoredList);

    return 0;
}
