#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, tmp, c = 0;
    cin >> n >> k;
    int sum = 0;
    if(n < 1 || n > 100000 || k < 1 || (k > n / 2 + 1)) return 0;

    queue <int> inp;

    int i = 0;
    for (i; i < k; i++) {
        cin >> tmp;
        sum += tmp;
        inp.push(tmp);
    }
    if (sum % 2 == 0) c++;

    while (i < n) {
        cin >> tmp;
        inp.push(tmp);
        sum = sum - inp.front() + tmp;
        if (sum % 2 == 0) c++;
        inp.pop();
        i++;
    }
    cout << c;
    return 0;
}
