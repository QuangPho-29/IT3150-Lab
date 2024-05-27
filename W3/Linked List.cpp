#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node* before;
    Node* after;

    int key;

    Node (int val) {
        key = val;
        before = nullptr;
        after = nullptr;
    }
};

struct LinkList {
    Node* first;
    Node* last;

    LinkList (int val) {
        first = new Node(val);
        last = first;
    }

    void insertNode (int val) {
        Node* tmp = new Node(val);
        tmp->before = last;
        last->after = tmp;
        last = tmp;
    }

    Node* findNode (int val) {
        Node* current = first;
        while (current != nullptr) {
            if (val == current->key) {
                return current;
            }
            current = current->after;
        }
        return nullptr;
    }

    void addLast (int val) {
        if (findNode(val) != nullptr) return;

        Node* newNode = new Node(val);
        last->after = newNode;
        newNode->before = last;
        last = newNode;
        return;
    }

    void addFirst (int val) {
        if (findNode(val) != nullptr) return;

        Node* newNode = new Node(val);
        newNode->after = first;
        first->before = newNode;
        first = newNode;
    }

    void addAfter(int val2, int val1) {
        Node* node1 = findNode(val1);
        if (node1 == nullptr || findNode(val2) != nullptr) return;

        Node* newNode = new Node(val2);
        Node* nextNode = node1->after;

        newNode->after = nextNode;
        newNode->before = node1;
        node1->after = newNode;
        if (nextNode) {
            nextNode->before = newNode;
        }

        if (node1 == last) {
            last = newNode;
        }
    }

    void addBefore(int val2, int val1) {
        Node* node1 = findNode(val1);
        if (node1 == nullptr || findNode(val2) != nullptr) return;

        Node* newNode = new Node(val2);
        Node* prevNode = node1->before;

        newNode->before = prevNode;
        newNode->after = node1;
        node1->before = newNode;
        if (prevNode) {
            prevNode->after = newNode;
        }

        if (node1 == first) {
            first = newNode;
        }
    }


    void removeNode (int val) {
        Node* node = findNode(val);
        if (node == nullptr) {
            return;
        }

        if (node->before) {
            node->before->after = node->after;
        } else {
            first = node->after;
        }

        if (node->after) {
            node->after->before = node->before;
        } else {
            last = node->before;
        }

        delete node;
    }

    void reverseList() {
        Node* current = first;
        Node* tmp = nullptr;

        while (current != nullptr) {
            tmp = current->before;
            current->before = current->after;
            current->after = tmp;
            if (current->before != nullptr) {
                current = current->before;
            } else {
                break;
            }
        }

        Node* temp = first;
        first = last;
        last = temp;
    }


    void printList () {
        Node* current = first;
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->after;
        }
        return;
    }
};

int main() {
    int n;
    cin >> n;
    int tmp;
    cin >> tmp;
    LinkList link(tmp);

    for (int i = 1; i < n; i++) {
        cin >> tmp;
        link.insertNode(tmp);
    }

    string command;
    int u, v;

    cin >> command;
    while(command != "#") {
        if (command == "addlast") {
            cin >> u;
            link.addLast(u);
        }
        else if (command == "addfirst") {
            cin >> u;
            link.addFirst(u);
        }
        else if (command == "addafter") {
            cin >> u >> v;
            link.addAfter(u, v);
        }
        else if (command == "addbefore") {
            cin >> u >> v;
            link.addBefore(u, v);
        }
        else if (command == "remove") {
            cin >> v;
            link.removeNode(v);
        }
        else if (command == "reverse") {
            link.reverseList();
        }
        cin >> command;
    }

    link.printList();

    return 0;
}
