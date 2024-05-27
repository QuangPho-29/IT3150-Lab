#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    long long tmp;
    cin >> n;
    set <long long> arr;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (arr.count(tmp)) {
            cout << 1 << endl;
            continue;
        }
        arr.insert(tmp);
        cout << 0 << endl;
    }
    return 0;
}
