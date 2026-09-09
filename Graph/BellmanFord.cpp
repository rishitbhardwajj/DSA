#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for(int i = 1; i < V; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    int V = 2;
    vector<vector<int>> edges = {{0, 1, 9}};
    int S = 0;

    Solution obj;
    vector<int> ans = obj.bellmanFord(V, edges, S);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}