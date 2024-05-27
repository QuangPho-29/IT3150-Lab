#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    long long hashCode = 0;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        int k = s.length();
        for (int j = 0; j < k; j++) {
            hashCode = ((hashCode << 8) + s[j]) % m;
        }
        cout << hashCode << '\n';
        hashCode = 0;
    }
}
