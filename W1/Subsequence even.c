#include <iostream>

using namespace std;

int main() {
    int n, k, start, tmp, c = 0;
    cin >> n >> k >> start;
    int sum = start;
    if(n < 1 || n > 100000 || k < 1 || k > n / 2) return 0;

    vector <int> inp;

    int i = 1;
    for (i; i < k; i++) {
        cin >> tmp;
        sum += tmp;
        inp.push_back(tmp);
    }

    while (i < n) {
        if (sum % 2 == 0) c++;
        cin >> tmp;
        inp.push_back(tmp);
        sum = sum - start + sum;
        start = inp.pop_top;
        i++;
    }
    cout << c;
    return 0;
}
