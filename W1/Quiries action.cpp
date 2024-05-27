#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp, minV = INT_MAX, maxV = INT_MIN, sum = 0;
    vector<int> inp;

    cin >> n;
    if (n < 1 || n > 10000) {
        return 0;
    }

    cin >> tmp;
    while (tmp != "*") {
        minV = (minV < tmp) ? minV : tmp;
        maxV = (maxV < tmp) ? tmp : maxV;
        sum += tmp;
        inp.push_back(tmp);
        cin >> tmp
    }

    string s;
    cin >> s;
    while(s != "***") {

        if (s == "find-max") {
            cout << maxV << endl;
            continue;
        }
        if (s == "find-min") {
            cout << minV << endl;
            continue;
        }
        if (s == "sum") {
            cout << sum << endl;
        }

        cin >> s;

    }
    for (int i : inp) cout << i << ' ';
    cout << endl << minV << ' ' << maxV << ' ' << sum;
    return 0;
}
