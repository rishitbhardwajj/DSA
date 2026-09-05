#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, src, dst, K;
    cin >> n >> src >> dst >> K;

    vector<vector<int>> adj[n];

    int f;
    cin >> f;

    for (int i = 0; i < f; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    queue<pair<int, pair<int, int>>> q;

    // {stops, {node, cost}}
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > K)
            continue;

        for (auto iter : adj[node]) {
            int adjNode = iter[0];
            int edW = iter[1];

            if (cost + edW < dist[adjNode] && stops <= K) {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if (dist[dst] == 1e9)
        cout << -1;
    else
        cout << dist[dst];

    return 0;
}