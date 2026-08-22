#include <bits/stdc++.h>
using namespace std;

bool check(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (check(i, adj, color) == false) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is Not Bipartite";

    return 0;
}