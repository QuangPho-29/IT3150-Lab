#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
int n, m, maxV, sum = 0;

void solveEquation (int k) {
    if (k == n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
            sum += arr[i];
        }
        cout << m - sum << ' ' << endl;
        return;
    }

    for (int i = 1; i <= maxV; i++) {
        arr[k] = i;
        sum += i;
        if (sum > m - 1) {
            sum -= i;
            continue;
        }
        solveEquation(k + 1);
        sum -= i;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        arr.push_back(0);
    }

    n--;
    maxV = m - n;

    solveEquation(0);
    return 0;
}
