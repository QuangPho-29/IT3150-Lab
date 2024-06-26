#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define INF INT_MAX

using namespace std;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void add_edge(int u, int v, int cap) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Add reverse path with 0 initial capacity
    capacity[u][v] = cap;
}

int main() {
    int s, t;
    cin >> n >> m;
    cin >> s >> t;

    // Adjust indices if nodes are 1-indexed
    s--; t--;

    // Initialize adjacency list and capacity matrix
    capacity.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());

    // Read the edges
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        // Adjust indices if nodes are 1-indexed
        u--; v--;

        add_edge(u, v, c);
    }

    // Calculate max flow
    int max_flow = maxflow(s, t);
    cout << max_flow << endl;

    return 0;
}
