#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
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

    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    vector<int> numOfIslands(
        int n,
        int m,
        vector<vector<int>>& operators
    ) {
        DisjointSet ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        vector<int> ans;

        for (auto it : operators) {

            int row = it[0];
            int col = it[1];

            if (vis[row][col]) {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int ind = 0; ind < 4; ind++) {

                int adjr = row + dr[ind];
                int adjc = col + dc[ind];

                if (isValid(adjr, adjc, n, m)) {

                    if (vis[adjr][adjc] == 1) {

                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;

                        if (ds.findUPar(nodeNo) !=
                            ds.findUPar(adjNodeNo)) {

                            cnt--;

                            ds.unionBySize(
                                nodeNo,
                                adjNodeNo
                            );
                        }
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> operators(k, vector<int>(2));

    for (int i = 0; i < k; i++) {
        cin >> operators[i][0]
            >> operators[i][1];
    }

    Solution obj;

    vector<int> ans =
        obj.numOfIslands(n, m, operators);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}