#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floyd(int v, vector<vector<int>> &G) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (G[i][k] != INT_MAX && G[k][j] != INT_MAX)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    // Initialize the graph with INT_MAX and 0 for diagonal
    vector<vector<int>> G(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < v; i++)
        G[i][i] = 0;

    // Read edges
    for (int i = 0; i < e; i++) {
        int u, v1, w;
        cin >> u >> v1 >> w;
        G[u][v1] = w; // If undirected graph, also set G[v1][u] = w;
    }

    floyd(v, G);

    // Print the result
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (G[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << G[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
