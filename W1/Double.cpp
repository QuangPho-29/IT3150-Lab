#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if ( n < 1) return 0;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << i*i << endl;
    }
}
