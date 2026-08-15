#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> adj(n);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        cout << i << " -> ";

        for (int j : adj[i]) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}