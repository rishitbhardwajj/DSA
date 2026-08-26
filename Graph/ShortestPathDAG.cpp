#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        int v = it.first;

        if (!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    vector<int> vis(N, 0);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    return dist;
}

int main() {
    int N, M;

    cout << "Enter number of vertices and edges: ";
    cin >> N >> M;

    vector<vector<int>> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < M; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    vector<int> ans = shortestPath(N, M, edges);

    cout << "Shortest distances from source 0:\n";

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}