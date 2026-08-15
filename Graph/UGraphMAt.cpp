#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}