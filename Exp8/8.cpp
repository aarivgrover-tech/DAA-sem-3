#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

void prim(int graph[100][100], int n) {
    int key[100], p[100];
    bool visited[100];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    p[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                p[v] = u;
            }
        }
    }

    int total = 0;

    cout << "\nPrim's MST:\n";

    for (int i = 1; i < n; i++) {
        cout << p[i] << " - " << i << " : " << graph[i][p[i]] << endl;
        total += graph[i][p[i]];
    }

    cout << "Minimum Cost = " << total << endl;
}

void kruskal(Edge edges[], int n, int e) {
    sort(edges, edges + e, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;
    int count = 0;

    cout << "\nKruskal's MST:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v << " : " << edges[i].w << endl;
            total += edges[i].w;
            unite(u, v);
            count++;
        }
    }

    cout << "Minimum Cost = " << total << endl;
}

int main() {
    int n, e;
    int graph[100][100];
    Edge edges[100];

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cin >> e;

    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    prim(graph, n);
    kruskal(edges, n, e);

    return 0;
}