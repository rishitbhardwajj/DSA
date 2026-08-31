#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];

                if (dis + edgW < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S;
    cin >> S;

    Solution obj;
    vector<int> ans = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
        cout << ans[i] << " ";

    return 0;
}