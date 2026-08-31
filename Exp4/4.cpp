#include <iostream>
#include <vector>

using namespace std;
// Aariv Grover 25/DA/001
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    if (!(cin >> vertices)) return 0;
    
    cout << "Enter the number of edges: ";
    if (!(cin >> edges)) return 0;

    vector<vector<int>> adj(vertices);
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(vertices, false);
    vector<vector<int>> components;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            components.push_back(component);
        }
    }

    cout << "Number of connected components: " << components.size() << "\n";
    for (size_t i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}