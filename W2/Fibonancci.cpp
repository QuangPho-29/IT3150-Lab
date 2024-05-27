#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> arr (n);
    arr[0] = 0;
    arr[1] = 1;
    int k = 2;
    while(k < n) {
        arr[k] = arr[k - 1] + arr[k - 2];
        k++;
    }
    cout << arr[k - 1];
    return 0;
}
