#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> adjRev[V];
    int indegree[V] = {0};

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (auto it : adjRev[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> safeNodes = eventualSafeNodes(V, adj);

    for (auto it : safeNodes) {
        cout << it << " ";
    }

    return 0;
}