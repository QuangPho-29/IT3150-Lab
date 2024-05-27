#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int k, n;
    cin >> k >> n;

    vector <vector <long long>> C (n + 1, vector <long long> (k + 1, 0));
    for (int i = 0; i <= n; i++) {
        int a = i < k ? i : k;
        for (int j = 0; j <= a; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
    }

    cout << C[n][k];

    return 0;
}
