#include <bits/stdc++.h>

using namespace std;

int main() {
    string p1, p2, t;
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);

    size_t start = t.find(p1);
    int lenT = t.length(), lenP1 = p1.length(), lenP2 = p2.length();
    while (start != string::npos) {
        t.erase(start, lenP1);
        t.insert(start, p2);
        start = t.find(p1);
    }
    cout << t;
    return 0;
}
