#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mul;
    if (100 % n == 0) {
        mul = 100;
    }
    else {
        mul = (100 / n + 1) * n;
    }
    while (mul < 1000) {
        cout << mul << ' ';
        mul += n;
    }
    return 0;
}
