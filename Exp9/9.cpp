#include <iostream>
using namespace std;

int main() {
    int n, src;
    cin >> n;

    int cost[10][10], dist[10], visited[10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 9999;
        }
        dist[i] = 9999;
        visited[i] = 0;
    }

    cin >> src;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = 9999, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != 9999 &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " = ";
        if (dist[i] == 9999)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}