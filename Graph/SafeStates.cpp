#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis,
              vector<int>& pathVis, vector<int>& check) {

    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node]) {

        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis, check)) {
                check[node] = 0;
                return true;
            }
        }

        else if (pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;

    return false;
}

vector<int> eventualSafeNodes(int V, vector<vector<int>>& adj) {

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    vector<int> safeNodes;

    for (int i = 0; i < V; i++) {
        if (check[i] == 1) {
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> safeNodes = eventualSafeNodes(V, adj);

    for (int node : safeNodes) {
        cout << node << " ";
    }

    return 0;
}