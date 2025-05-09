﻿#include <iostream>
#include <fstream>

using namespace std;

struct SingleList {
    int data;
    SingleList* next;
};

void printList(SingleList* head) {
    int counter = 0;
    while (head) {
        cout << "[" << counter << "]" << head->data << " -> ";
        head = head->next;
        counter++;
    }
    cout << "nullptr\n";
}

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
            start = cur;
        }
        else
        {
            prev->next = cur;
        }

        prev = cur;
    }

    return start;
}

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
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

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
        if (current->next == nullptr) return;
        current = current->next;
    }

    if (current->next == nullptr) return;

    SingleList* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void insertNodeByIndex(SingleList*& head, int index, int value) {
    if (index < 0) return;

    SingleList* newNode = new SingleList;
    newNode->data = value;
    newNode->next = nullptr;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    SingleList* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            delete newNode;
            return;
        }
        current = current->next;
    }

    if (current == nullptr) {
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteList(SingleList* head) {
    while (head != nullptr) {
        SingleList* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "The list is empty\n";
}

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
