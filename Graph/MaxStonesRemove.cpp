#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]) {
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes;

        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);

            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;

        for(auto it : stoneNodes) {
            if(ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }

        return n - cnt;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> stones(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> stones[i][0] >> stones[i][1];
    }

    Solution obj;

    cout << obj.maxRemove(stones, n);

    return 0;
}