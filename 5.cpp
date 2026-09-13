#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    // DFS variables
    vector<int> discoveryTime;
    vector<int> low;
    vector<bool> visited;
    vector<bool> articulationPoint;

    int timer;

    void DFS(int u, int parent) {
        visited[u] = true;
        discoveryTime[u] = low[u] = timer++;

        int children = 0;

        for (int v : adj[u]) {

            // Ignore the edge to parent
            if (v == parent)
                continue;

            if (!visited[v]) {
                children++;

                DFS(v, u);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Articulation point condition
                if (parent != -1 && low[v] >= discoveryTime[u])
                    articulationPoint[u] = true;
            }
            else {
                // Back edge
                low[u] = min(low[u], discoveryTime[v]);
            }
        }

        // Root of DFS tree is articulation point
        if (parent == -1 && children > 1)
            articulationPoint[u] = true;
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);

        discoveryTime.resize(V);
        low.resize(V);
        visited.resize(V, false);
        articulationPoint.resize(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {

        // Graph may be disconnected
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(i, -1);
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (articulationPoint[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}
