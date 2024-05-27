#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
vector <bool> isSafe;
int n;

void generateSequence (int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (isSafe[i] == true) {
                isSafe[i] = false;
                arr[k] = i + 1;
                generateSequence(k + 1);
                isSafe[i] =true;
            }
        }
    }
    return;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        arr.push_back(0);
        isSafe.push_back(true);
    }
    generateSequence(0);
    return 0;
}
