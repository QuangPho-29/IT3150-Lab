#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

int N, M, s, t;
const int MAXN = 10000;
int capacity[MAXN][MAXN];
int flowPassed[MAXN][MAXN];
vector<int> graph[MAXN];

bool bfs(int parent[]) {
    memset(parent, -1, sizeof(int) * N);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next] - flowPassed[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next] - flowPassed[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int edmondsKarp() {
    int total_flow = 0;
    int parent[MAXN];

    int new_flow;

    while (new_flow = bfs(parent)) {
        total_flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            flowPassed[prev][cur] += new_flow;
            flowPassed[cur][prev] -= new_flow;
            cur = prev;
        }
    }

    return total_flow;
}

int main() {
    cin >> N >> M;
    cin >> s >> t;

    int u, v, c;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        graph[u].push_back(v);
        graph[v].push_back(u); // For reverse path in residual graph
        capacity[u][v] = c;
    }

    cout << edmondsKarp() << endl;

    return 0;
}
