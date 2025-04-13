#include <iostream>
#include <fstream>

struct QueueElem {
    int data;
    QueueElem* next;
};

struct Queue {
    QueueElem* front;
    QueueElem* back;
    int size;

    void init()
    {
        front = nullptr;
        back = front;
        size = 0;
    }

    void push(int data)
    {
        QueueElem* tmp = new QueueElem;
        tmp->data = data;
        tmp->next = nullptr;
        if (size == 0)
        {
            front = tmp;
            back = tmp;
        }
        else
        {
            back->next = tmp;
            back = tmp;
        }
        size++;
    }

    int pop()
    {
        int value = front->data;
        QueueElem* tmp = front;
        if (size == 1) { back = nullptr; }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }

    //QueueElem* front() { return front; }
    //QueueElem* back() { return back; }

    void printQueue() const
    {
        QueueElem* current = front;
        while (current) {
            std::cout << "[" << current->data << "]" << std::endl;
            current = current->next;
        }
    }

    void writeQueue() const {
        std::string path = "11.4.txt";
        std::ofstream file(path);

        if (file.is_open()) {
            std::cout << path << " opened for writing\n";

            QueueElem* current = front;
            while (current != nullptr) {
                file << current->data << std::endl;
                current = current->next;
            }

            std::cout << path << " saved.\n";
        }
        else {
            std::cout << "Can't open " << path << ".\n";
        }

        file.close();
    }

    void deleteQueue() {
        while (front) {
            QueueElem* temp = front;
            front = front->next;
            delete temp;
        }
        back = nullptr; // не забудем обнулить back
        size = 0;
        std::cout << "The queue is empty\n";
    }

    Queue RestoreQueue(const std::string& path) {
        std::ifstream file(path);
        Queue queue{};
        queue.init();

        if (!file.is_open()) {
            std::cout << "Can't open file for reading.\n";
            return queue;
        }

        std::cout << path << " opened for reading\n";

        int value;
        while (file >> value) {
            queue.push(value);
        }

        file.close();
        std::cout << path << " loaded into queue.\n";
        return queue;
    }
};

Queue createQueue(int size)
{
    Queue queue{};
    queue.init();
    int data;
    for (int i = 0; i < size; i++)
    {
        data = rand() % 10;
        queue.push(data);
    }
    return queue;
}

int main()
{
    // Создание
    int size;
    std::cin >> size;
    Queue q = createQueue(size);
    q.printQueue();

    // Добавление
    int add;
    std::cout << "How much elements to add? ";
    std::cin >> add;
    for (int i = 0; i < add; i++)
    {
        q.push(rand() % 10);
    }

    q.printQueue();

    // Удаление
    int del;
    std::cout << "How much elements to delete? ";
    std::cin >> del;
    if (del > size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Deleted: " << q.pop() << std::endl;
        }
    }
    for (int i = 0; i < del; i++)
    {
        std::cout << "Deleted: " << q.pop() << std::endl;
    }

    q.printQueue();

    // Запись в файл
    q.writeQueue();

    // Удаление очереди
    q.deleteQueue();
    q.printQueue();

    // Восстановление из файла
    Queue q2 = q.RestoreQueue("11.4.txt");
    q2.printQueue();
}