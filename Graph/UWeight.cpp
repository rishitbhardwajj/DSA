#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    for (int i = 0; i < n; i++) {
        cout << i << " -> ";

        for (auto it : adj[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }

        cout << endl;
    }

    return 0;
}