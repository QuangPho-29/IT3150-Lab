#include <bits/stdc++.h>

using namespace std;

int v, e;
int **dist;

void input() {
    cin >> v >> e;
    dist = new int* [v + 1];

    for (int i = 1; i <= v; i++) {
        dist[i] = new int [v + 1];
        for (int j = 1; j <= v; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    int u1, u2, w;
    for (int i = 0; i < e; i++) {
        cin >> u1 >> u2 >> w;
        dist[u1][u2] = w;
    }
    return;
}

void printOut() {
    for (int i  = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void FloydWarshall() {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void deleteAllocated() {
    for (int i = 1;i <= v; i++) {
        delete[] dist[i];
    }
    delete[] dist;
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    FloydWarshall();
    printOut();

    deleteAllocated();

    return 0;
}
