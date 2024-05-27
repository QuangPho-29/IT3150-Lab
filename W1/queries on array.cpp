#include <bits/stdc++.h>

using namespace std;

vector <int> arr;

int findMax(int l, int r) {
    int maxV = arr[l];
    for (int i = l + 1; i < r; i++) {
        if(arr[i] > maxV) maxV = arr[i];
    }

    return maxV;
}

int findMin(int l, int r) {
    int minV = arr[l];
    for (int i = l + 1; i < r; i++) {
        if(arr[i] < minV) minV = arr[i];
    }

    return minV;
}

int main() {
    int n, tmp, maxV = -1000, minV = 1000, sum = 0;
    cin >> n;

    if(n < 1 || n > 10000) {
        return 0;
    }

    for (int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
        sum += tmp;
        if (tmp > maxV) {
            maxV = tmp;
        }
        if (tmp < minV) {
            minV = tmp;
        }

    }

    string s;
    cin >> s;
    cin >> s;

    while(s != "***") {
        if (s == "find-max") {
            cout << maxV << endl;
        }
        else if (s == "find-min") {
            cout << minV << endl;
        }
        else if (s == "sum") {
            cout << sum << endl;
        }
        else if (s == "find-max-segment") {
            int l, r;
            cin >> l >> r;
            cout << findMax(l - 1, r) << endl;
        }
        else if (s == "find-min-segment") {
            int l, r;
            cin >> l >> r;
            cout << findMin(l - 1, r) << endl;
        }
        cin >> s;
    }
    return 0;
}
