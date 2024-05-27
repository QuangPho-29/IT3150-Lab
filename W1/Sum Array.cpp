#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n;
    int tmp, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
}
