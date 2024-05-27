#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    pair <Node*, Node*> child;

    Node (int value) {
        val = value;
    };
};

struct BST {
    Node* rootPointer;

    BST (int val) {
        rootPointer = new Node(val);
    }

    void insertNode (int val, Node* current) {
        if (val == current->val) return;
        if (val < current->val) {
            if (current->child.first == nullptr) {
                current->child.first = new Node (val);
            }
            else {
                insertNode(val, current->child.first);
            }
        }
        else {
            if (current->child.second == nullptr) {
                current->child.second = new Node (val);
            }
            else {
                insertNode(val, current->child.second);
            }
        }
        return;
    }

    void preOrdered (Node* current) {
        if (current == nullptr) return;

        cout << current->val << " ";
        preOrdered(current->child.first);
        preOrdered(current->child.second);

        return;
    }
};

int main() {
    string command;
    int param;

    cin >> command >> param;
    BST tree (param);

    cin >> command;
    while (command != "#") {
        if (command == "insert") {
            cin >> param;
            tree.insertNode(param, tree.rootPointer);
        }
        cin >> command;
    }
    tree.preOrdered(tree.rootPointer);
    return 0;
}
