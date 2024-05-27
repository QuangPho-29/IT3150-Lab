#include <bits/stdc++.h>

using namespace std;

int main () {
    stack <char> check;
    char tmp, inp;

    while (cin >> inp) {
        if (inp == '(' || inp == '[' || inp == '{') {
            check.push(inp);
        } else {
            if (check.empty()) {
                cout << 0;
                return 0;
            }
            tmp = check.top();
            check.pop();
            if ((inp == ')' && tmp != '(') || (inp == ']' && tmp != '[') || (inp == '}' && tmp != '{')) {
                cout << 0;
                return 0;
            }
        }
    }
    if (check.empty()) cout << 1;
    else cout << 0;
    return 0;
}
