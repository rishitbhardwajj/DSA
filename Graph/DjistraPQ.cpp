#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);

        for(int i = 0; i < V; i++)
            dist[i] = 1e9;

        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if(dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
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

    for(int i = 0; i < E; i++)
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

    for(int i = 0; i < V; i++)
        cout << ans[i] << " ";

    return 0;
}