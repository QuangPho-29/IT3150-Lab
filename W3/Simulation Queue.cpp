#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node (int val) : value(val), next(nullptr){};
};

struct IntQueue {
    Node* frontPointer;
    Node* backPointer;
    int sizeQ = 0;

    void push (int val) {
        Node* tmp = new Node(val);
        if (sizeQ == 0) {
            frontPointer = backPointer = tmp;
            sizeQ++;
        }
        else {
            backPointer->next = tmp;
            backPointer = tmp;
            sizeQ++;
        }
        return;
    }

    void pop () {
        if(sizeQ == 0) {
            cout << "NULL" << endl;
            return;
        }
        else {
            Node* tmp = frontPointer;
            cout << frontPointer->value << endl;
            frontPointer = frontPointer->next;
            delete tmp;
            sizeQ--;
            return;
        }
    }
};

int main() {
    IntQueue q;
    string inp;
    cin >> inp;
    int tmp;
    while (inp != "#") {
        if (inp == "PUSH") {
            cin >> tmp;
            q.push(tmp);
            cin >> inp;
            continue;
        }
        if (inp == "POP") {
            q.pop();
            cin >> inp;
            continue;
        }
    }
    return 0;
}
