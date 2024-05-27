#include <bits/stdc++.h>

using namespace std;

int v, e, s, t;
vector <pair <int, int>> *graph;
int* dist;

void input() {
    cin >> v >> e;

    graph = new vector <pair <int, int>> [v + 1];
    dist = new int [v + 1];
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
    }

    int u1, u2, w;
    for (int i = 0; i < e; i++) {
        cin >> u1 >> u2 >> w;
        graph[u1].push_back({w, u2});
    }

    cin >> s >> t;
}

void Dijkstra() {
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> minQueue;
    dist[s] = 0;

    minQueue.push({0, s});
    int curDist, curVer;
    while (!minQueue.empty()) {
        curDist = minQueue.top().first;
        curVer = minQueue.top().second;
        minQueue.pop();

        if (curVer == t) return;
        if (curDist > dist[curVer]) continue;

        int d, v;
        for (pair <int, int> near : graph[curVer]) {
            d = near.first;
            v = near.second;

            if (dist[curVer] + d < dist[v]) {
                dist[v] = dist[curVer] + d;
                minQueue.push({dist[v], v});
            }
        }
    }
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    Dijkstra();
    if (dist[t] < INT_MAX) cout << dist[t];
    else cout << -1;

    delete[] dist;
    delete[] graph;

    return 0;
}
