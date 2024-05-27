#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 1) return 0;
    int tmp, cOdd = 0, cEven = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp % 2 == 0) {
            cEven++;
        }
        else {
            cOdd++;
        }
    }

    cout << cOdd << ' ' << cEven;
    return 0;
}
