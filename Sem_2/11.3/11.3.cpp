#include <iostream>
#include <fstream>

// Один элемент стека
struct StackElem {
	int data;
	StackElem* next;
};

struct Stack {
	StackElem* top;
	int size;

	void init()
	{
		top = nullptr;
		size = 0;
	}

	// Добавление элемента
	void push(int data)
	{
		StackElem* cur = new StackElem;
		cur->data = data;
		cur->next = top;
		top = cur;
		size++;
	}

	int pop()
	{
		if (top == nullptr) {
			std::cerr << "Стек пуст!" << std::endl;
			exit(1);
		}
		else
		{
			int value = top->data;
			StackElem* tmp = top;
			top = top->next;
			size--;
			delete tmp;
			return value;
		}
	}

	void printStack(const Stack& stack)
	{
		StackElem* current = stack.top;
		while (current) {
			std::cout << "[" << current->data << "]" << std::endl;
			current = current->next;
		}
	}

	void writeStack() {
		std::string path = "11.3.txt";
		std::ofstream file_1(path);  // можно открыть файл так, проще

		if (file_1.is_open()) {
			std::cout << "11.3.txt opened for writing" << std::endl;

			StackElem* current = top;
			while (current != nullptr) {
				file_1 << current->data << std::endl;
				current = current->next;
			}
			std::cout << path << " saved.\n";
		}
		else {
			std::cout << "Can't open " << path << "\n";
		}

		file_1.close();
	}

	void deleteStack() {
		while (top) {
			StackElem* temp = top;
			top = top->next;
			delete temp;
		}
		std::cout << "The stack is empty\n";
	}

	StackElem* RestoreStack(const std::string& path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			std::cout << "Can't open file for reading." << std::endl;
			return nullptr;
		}

		StackElem* tempTop = nullptr;
		int value;

		while (file >> value) {
			StackElem* newElem = new StackElem{ value, tempTop };
			tempTop = newElem;
		}
		file.close();

		StackElem* finalTop = nullptr;
		while (tempTop) {
			StackElem* newElem = new StackElem{ tempTop->data, finalTop };
			finalTop = newElem;

			StackElem* toDelete = tempTop;
			tempTop = tempTop->next;
			delete toDelete;
		}

		return finalTop;
	}

	StackElem* peek() {
		return top;
	}
};

Stack createStack(int size)
{
	Stack stack{};
	stack.init();
	int data;
	for (int i = 0; i < size; i++)
	{
		data = rand() % 10;
		stack.push(data);
	}
	return stack;
}

int main() {
	// Создание стека
	int size;
	std::cout << "Type the stack size: ";
	std::cin >> size;
	Stack stack = createStack(size);

	stack.printStack(stack);

	// Добавление элементов
	int add;
	std::cout << "Type a number to add: ";
	std::cin >> add;
	stack.push(add);

	stack.printStack(stack);


	// Удаление элементов
	int del;
	std::cout << "How much elements to delete? ";
	std::cin >> del;
	if (del > size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Deleted: " << stack.pop() << std::endl;
		}
	}
	for (int i = 0; i < del; i++)
	{
		std::cout << "Deleted: " << stack.pop() << std::endl;
	}

	stack.printStack(stack);

	// Запись стека в файл
	stack.writeStack();

	// Удаление стека
	stack.deleteStack();
	stack.printStack(stack);

	// Восстановление стека
	StackElem* restoredTop = stack.RestoreStack("11.3.txt");

	Stack restoredStack;
	restoredStack.top = restoredTop;
	restoredStack.size = 0;

	std::cout << "\nRestored stack:\n";
	stack.printStack(restoredStack);

	while (restoredStack.top) {
		StackElem* tmp = restoredStack.top;
		restoredStack.top = restoredStack.top->next;
		delete tmp;
	}

	return 0;
}
