#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(0); cout.tie(0);
    int c = 0, n, m;
    cin >> n >> m;

    map <int, int> inp;
    int tmp;

    cin >> tmp;
    inp[tmp] = 1;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (tmp < 1 || tmp > m) continue;
        if (inp[m - tmp] == 0) {
            inp[tmp] = 1;
        }

        else {
            c++;
        }
    }
    cout << c;
    return 0;
}
