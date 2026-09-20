#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {

                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int mstWt = 0;

        for (auto it : edges) {

            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {

                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 4});
    adj[3].push_back({1, 4});

    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    Solution obj;

    cout << "Minimum Spanning Tree Weight: "
         << obj.spanningTree(V, adj);

    return 0;
}