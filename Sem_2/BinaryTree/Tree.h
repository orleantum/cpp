#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    char* data;
    Node* left;
    Node* right;
};

char* copyString(const char* str) {
    char* result = new char[strlen(str) + 1];
    strcpy(result, str);
    return result;
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete[] root->data;
        delete root;
    }
}

Node* buildBalancedTree(const vector<const char*>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* node = new Node{copyString(arr[mid]), nullptr, nullptr};
    node->left = buildBalancedTree(arr, start, mid - 1);
    node->right = buildBalancedTree(arr, mid + 1, end);
    return node;
}

void printTree(Node* node, const string& prefix = "", bool isLeft = true, bool isRoot = true) {
    if (!node) return;

    if (isRoot) {
        cout << node->data << endl;
    } else {
        cout << prefix;
        cout << (isLeft ? "├── " : "└── ");
        cout << node->data << endl;
    }

    bool hasLeft = node->left != nullptr;
    bool hasRight = node->right != nullptr;

    if (hasLeft)
        printTree(node->left, prefix + (isRoot ? "" : (isLeft ? "│   " : "    ")), true, false);
    if (hasRight)
        printTree(node->right, prefix + (isRoot ? "" : (isLeft ? "│   " : "    ")), false, false);
}

int countOccurrences(Node* root, const char* key) {
    if (!root) return 0;
    int count = (strcmp(root->data, key) == 0) ? 1 : 0;
    return count + countOccurrences(root->left, key) + countOccurrences(root->right, key);
}

void insertBST(Node*& root, const char* key) {
    if (!root) {
        root = new Node{copyString(key), nullptr, nullptr};
        return;
    }
    if (strcmp(key, root->data) < 0)
        insertBST(root->left, key);
    else
        insertBST(root->right, key);
}

Node* searchBST(Node* root, const char* key) {
    if (!root) return nullptr;
    int cmp = strcmp(key, root->data);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, const char* key) {
    if (!root) return nullptr;

    int cmp = strcmp(key, root->data);
    if (cmp < 0) {
        root->left = deleteNode(root->left, key);
    } else if (cmp > 0) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left && !root->right) {
            delete[] root->data;
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete[] root->data;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete[] root->data;
            delete root;
            return temp;
        } else {
            Node* minNode = findMin(root->right);
            delete[] root->data;
            root->data = copyString(minNode->data);
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    return root;
}

void toSearchTree(Node* balancedRoot, Node*& bstRoot) {
    if (!balancedRoot) return;
    insertBST(bstRoot, balancedRoot->data);
    toSearchTree(balancedRoot->left, bstRoot);
    toSearchTree(balancedRoot->right, bstRoot);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void storeInOrder(Node* root, vector<const char*>& nodes) {
    if (!root) return;
    storeInOrder(root->left, nodes);
    nodes.push_back(copyString(root->data)); // важно: копируем строку
    storeInOrder(root->right, nodes);
}

Node* balanceBST(Node* root) {
    vector<const char*> nodes;
    storeInOrder(root, nodes);
    deleteTree(root);
    return buildBalancedTree(nodes, 0, static_cast<int>(nodes.size()) - 1);
}

#endif
