#include <bits/stdc++.h>

using namespace std;

int testCase, v, e, c = 0, start;
bool check;
bool *visited;
int **graph;

void DFS(int i) {
    visited[i] = true;
    c++;
    if (c == v) {
        if (check) return;
        if (graph[i][start] == 1) {
            check = true;
        }
        else {
            visited[i] = false;
            c--;
        }
    }
    else {
        for (int j = 1; j <= v; j++) {
            if (graph[i][j] == 1 && !visited[j]) {
                DFS(j);
            }
        }
        visited[i] = false;
        c--;
    }
}

void inputGraph() {
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
    cin >> testCase;
    for (int j = 0; j < testCase; j++) {
        inputGraph();
        for (int i = 1; i <= v; ++i) {
            if (!visited[i]) {
                start = i;
                DFS(i);
            }
        }
        if (check) cout << '1' << '\n';
        else cout << '0' <<'\n';
        check = false;
        delete[] visited;
        for (int i = 1; i <= v; i++) {
            delete[] graph[i];
        }
        delete[] graph;

    }

    return 0;
}
