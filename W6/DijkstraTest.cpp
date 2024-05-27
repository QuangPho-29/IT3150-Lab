#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    priority_queue<pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push ({10, 5});
    pq.push ({5, 10});
    pq.push ({4, 20});
    cout << pq.top().first;
    return 0;
}
