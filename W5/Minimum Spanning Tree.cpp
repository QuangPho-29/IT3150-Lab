#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u1, u2;
    int weight;

    Edge() {};

    Edge(int v1, int v2, int weigh) {
        u1 = v1;
        u2 = v2;
        weight = weigh;
    }
};

Edge* edgeSet;
int* parent, *deepLevel;
int v, e, totalWeight = 0;

void sortEdge() {
    sort(edgeSet, (edgeSet + e), [](Edge& e1, Edge& e2) {
            return e1.weight < e2.weight;
        });
}

int findRoot (int e) {
    return (parent[e] == e) ? e : findRoot(parent[e]);
}

/*void printEdge() {
    for (int i = 0; i < e; i++) {
        cout << edgeSet[i].u1 << ' ' << edgeSet[i].u2 << ' ' << edgeSet[i].weight << '\n';
    }
}*/

bool addEdgeCheck(Edge e) {
    int v1 = findRoot(e.u1);
    int v2 = findRoot(e.u2);

    if (v1 == v2) return false;
    if (deepLevel[v1] > deepLevel[v2]) swap(v1, v2);
    parent[v1] = v2;
    if (deepLevel[v1] == deepLevel[v2]) deepLevel[v2]++;
    return true;
}

void Kruskal() {
    for (int i = 0; i < e; i++) {
        if (addEdgeCheck(edgeSet[i])) {
            totalWeight += edgeSet[i].weight;
            //cout << edgeSet[i].u1 << ' ' << edgeSet[i].u2 << ' ' << edgeSet[i].weight << '\n';
        }
    }
}

void input() {
    cin >> v >> e;
    edgeSet = new Edge[e];
    parent = new int[v + 1];
    deepLevel = new int[v + 1];
    for(int i = 0; i <= v; i++) {
        parent[i] = i;
    }
    memset(deepLevel, 0, v + 1);

    int u1, u2, w;
    for (int i = 0; i < e; i++) {
        cin >> u1 >> u2 >> w;
        edgeSet[i] = Edge(u1, u2, w);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sortEdge();
    //printEdge();
    Kruskal();

    cout << totalWeight;
    delete [] edgeSet;
    delete [] parent;
    delete [] deepLevel;
    return 0;
}
