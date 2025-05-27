#include "tree.h"

int main() {
    vector<const char*> values = {"apple", "banana", "banana", "cherry", "date", "fig", "grape", "apple", "banana", "banana", "cherry", "date", "fig", "grape"};
    Node* balancedTree = buildBalancedTree(values, 0, static_cast<int>(values.size()) - 1);

    int choice;
    Node* bstTree = nullptr;
    char input[100];

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Печать сбалансированного дерева\n";
        cout << "2. Найти количество вхождений заданного ключа\n";
        cout << "3. Преобразовать в дерево поиска\n";
        cout << "4. Печать дерева поиска\n";
        cout << "5. Вставка в дерево поиска\n";
        cout << "6. Удаление из дерева поиска\n";
        cout << "7. Поиск в дереве поиска\n";
        cout << "8. Обходы дерева поиска\n";
        cout << "9. Балансировка дерева поиска\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nСбалансированное дерево:\n";
                printTree(balancedTree);
                break;
            case 2:
                cout << "Введите ключ: ";
                cin.getline(input, 100);
                {
                    int count = countOccurrences(balancedTree, input);
                    if (count)
                        cout << "Количество вхождений: " << count << endl;
                    else
                        cout << "Элементы с таким ключом не найдены.\n";
                }
                break;
            case 3:
                deleteTree(bstTree);
                bstTree = nullptr;
                toSearchTree(balancedTree, bstTree);
                cout << "Преобразование завершено.\n";
                break;
            case 4:
                if (bstTree)
                    printTree(bstTree);
                else
                    cout << "Дерево поиска не создано.\n";
                break;
            case 5:
                cout << "Введите значение для вставки: ";
                cin.getline(input, 100);
                insertBST(bstTree, input);
                break;
            case 6:
                cout << "Введите значение для удаления: ";
                cin.getline(input, 100);
                bstTree = deleteNode(bstTree, input);
                break;
            case 7:
                cout << "Введите значение для поиска: ";
                cin.getline(input, 100);
                if (searchBST(bstTree, input))
                    cout << "Элемент найден!\n";
                else
                    cout << "Элемент не найден.\n";
                break;
            case 8:
                cout << "\nПрямой (preorder): ";
                preorder(bstTree);
                cout << "\nСимметричный (inorder): ";
                inorder(bstTree);
                cout << "\nОбратный (postorder): ";
                postorder(bstTree);
                cout << endl;
                break;
            case 9:
                bstTree = balanceBST(bstTree);
                cout << "Балансировка завершена.\n";
                break;
            case 0:
                break;
            default:
                cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);

    deleteTree(balancedTree);
    deleteTree(bstTree);
    return 0;
}
