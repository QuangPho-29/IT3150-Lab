#include <bits/stdc++.h>

using namespace std;

struct Node {
    string key;
    pair<Node*, Node*> child;

    Node(string val) : key(val), child({nullptr, nullptr}) {}
};

struct binaryTree {
    Node* rootPointer = nullptr;

    bool findE(string s, Node* curNode) {
        if (curNode == nullptr) return false;
        if (curNode->key == s) return true;
        if (curNode->key > s) {
            return findE(s, curNode->child.first);
        } else {
            return findE(s, curNode->child.second);
        }
    }

    bool insertE(string inp) {
        Node* curNode = rootPointer;
        if (curNode == nullptr) {
            rootPointer = new Node(inp);
            return true;
        }
        string tmp;
        while (true) {
            tmp = curNode->key;
            if (tmp == inp) {
                return false;
            } else if (inp > tmp) {
                if (curNode->child.second == nullptr) {
                    curNode->child.second = new Node(inp);
                    return true;
                }
                curNode = curNode->child.second;
            } else {
                if (curNode->child.first == nullptr) {
                    curNode->child.first = new Node(inp);
                    return true;
                }
                curNode = curNode->child.first;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    binaryTree tree;

    string s;
    cin >> s;
    while (s != "*") {
        tree.insertE(s);
        cin >> s;
    }
    string command, param;
    cin >> command;
    while (command != "***") {
        if (command == "find") {
            cin >> param;
            cout << tree.findE(param, tree.rootPointer) << endl;
        }
        if (command == "insert") {
            cin >> param;
            cout << tree.insertE(param) << endl;
        }
        cin >> command;
    }

    return 0;
}
