#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;
int n;

void generateSequence (int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    else {
        for (int i = 0; i <= 1; i++) {
            arr[k] = i;
            generateSequence (k + 1);
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        arr.push_back(0);
    }
    generateSequence(0);
    return 0;
}
