#include <bits/stdc++.h>

using namespace std;

int v, e;
bool *visited;
int **graph;

void DFS(int i) {
    visited[i] = true;
    cout << i << ' ';
    for (int j = 1; j <= v; j++) {
        if (graph[i][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

void input() {
    cin >> v >> e;
    visited = new bool[v + 1];
    graph = new int *[v + 1];
    for (int i = 1; i <= v; i++) {
        graph[i] = new int[v + 1];
    }
    memset(visited, false, sizeof(bool) * (v + 1));
    for (int i = 1; i <= v; i++) {
        memset(graph[i], 0, sizeof(int) * (v + 1));
    }
    int x, y;
    for (int i = 1; i <= e; i++) {
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    delete[] visited;
    for (int i = 1; i <= v; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
