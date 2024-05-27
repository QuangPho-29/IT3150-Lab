#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* dad = nullptr;
    int id;
    vector <Node*> child;

    Node(int idNode, Node* dadNode) : id(idNode), dad(dadNode) {};
};

struct Tree {
    Node* rootPointer;

    void makeRoot (int id) {
        Node* tmp = new Node(id, nullptr);
        rootPointer = tmp;
        return;
    }

    Node* findNode(Node* currentNode, int targetId) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (currentNode->id == targetId) {
            return currentNode;
        }

        for (Node* child : currentNode->child) {
            Node* result = findNode(child, targetId);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    void insertNode(int childId, int dadId) {
        Node* dadNode = findNode(rootPointer, dadId);
        if (dadNode != nullptr) {
            dadNode->child.push_back(new Node(childId, dadNode));
        }
    }

    void postOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        for (Node* child : node->child) {
            postOrder(child);
        }

        cout << node->id << " ";
    }

    void preOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->id << " ";

        for (Node* child : node->child) {
            preOrder(child);
        }

        return;
    }

    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (!node->child.empty()) {
            inOrder(node->child.front());
        }

        cout << node->id << " ";

        int length = node->child.size();

        for (int i = 1; i < length; i++) {
            inOrder(node->child[i]);
        }
    }

};

int main() {
    string inp;
    int tmp1, tmp2;
    Tree t;

    cin >> inp;
    while (inp != "*") {
        if (inp == "Insert"){
            cin >> tmp1 >> tmp2;
            t.insertNode(tmp1, tmp2);
            cin >> inp;
            continue;
        }
        if (inp == "MakeRoot"){
            cin >>  tmp1;
            t.makeRoot(tmp1);
            cin >> inp;
            continue;
        }
        if (inp == "InOrder"){
            t.inOrder(t.rootPointer);
            cout << endl;
            cin >> inp;
            continue;
        }
        if (inp == "PreOrder"){
            t.preOrder(t.rootPointer);
            cout << endl;
            cin >> inp;
            continue;
        }
        if (inp == "PostOrder"){
            t.postOrder(t.rootPointer);
            cout << endl;
            cin >> inp;
            continue;
        }
    }
    return 0;
}
