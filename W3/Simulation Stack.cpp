#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node (int val) : value(val), next(nullptr){};
};

struct IntStack {
    Node* stackPointer;
    int sizeS = 0;

    void push (int val) {
        Node* tmp = new Node(val);
        tmp->next = stackPointer;
        stackPointer = tmp;
        sizeS++;
        return;
    }

    void pop () {
        if(sizeS == 0) {
            cout << "NULL" << endl;
            return;
        }
        else {
            Node* tmp = stackPointer;
            cout << stackPointer->value << endl;
            stackPointer = stackPointer->next;
            delete tmp;
            sizeS--;
            return;
        }
    }
};

int main() {
    IntStack s;
    string inp;
    cin >> inp;
    int tmp;
    while (inp != "#") {
        if (inp == "PUSH") {
            cin >> tmp;
            s.push(tmp);
            cin >> inp;
            continue;
        }
        if (inp == "POP") {
            s.pop();
            cin >> inp;
            continue;
        }
    }
    return 0;
}
