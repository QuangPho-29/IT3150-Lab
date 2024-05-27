#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    vector <Node*> child;

    Node (string Name) : name(Name) {};
};

struct familyTree {
    Node* rootPointer;
    unordered_map <string, Node*> family;

    void createRelation(string dadName, string childName){
        Node* child = getNode(childName);
        Node* dad = getNode(dadName);
        dad->child.push_back(child);
        return;
    }

    Node* getNode(string name) {
        if (family.count(name) == 0) {
            family[name] = new Node(name);
        }
        return family[name];
    }

    void descendants (Node* dad, int& countD) {
        countD += dad->child.size();
        for (Node* i : dad->child) {
            descendants(i, countD);
        }
        return;
    }

    int generation (Node* dad) {
        if (dad->child.empty()) {
            return 0;
        }
        int maxG = 0;
        for (Node* i : dad->child) {
            maxG = max(maxG, 1 + generation(i));
        }
        return maxG;
    }
};

int main() {
	string child, dad;

	familyTree fT;
	while  (cin >> child) {
		if (child == "***") {
            break;
        }
        cin >> dad;
        fT.createRelation (dad, child);
	}

    string command, param;
    while (cin >> command) {
        if (command == "***") {
            break;
        }
        cin >> param;
        if (command == "descendants") {
            int countD = 0;
            fT.descendants(fT.getNode(param), countD);
            cout << countD << endl;
            continue;
        }
        if (command == "generation") {
            cout << fT.generation(fT.getNode(param)) << endl;
            continue;
        }
    }

	return 0;
}
