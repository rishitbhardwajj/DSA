#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
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
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (ds.parent[i] == i)
                cnt++;
        }

        return cnt;
    }
};

int main() {
    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    Solution obj;

    cout << obj.numProvinces(adj, V);

    return 0;
}