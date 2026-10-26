#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    Edge edges[100];

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    int dist[100];

    for (int i = 0; i < n; i++)
        dist[i] = 999999;

    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 999999 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != 999999 && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected";
            return 0;
        }
    }

    cout << "Shortest distances from source " << src << ":" << endl;

    for (int i = 0; i < n; i++) {
        cout << src << " to " << i << " = ";

        if (dist[i] == 999999)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    cout << "No negative weight cycle detected";

    return 0;
}