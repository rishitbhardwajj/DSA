#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int, pair<int, int>>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int ds = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 4; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 &&
                    ds + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = ds + 1;

                    if (nrow == destination.first &&
                        ncol == destination.second)
                        return ds + 1;

                    q.push({ds + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1}
    };

    pair<int, int> source = {0, 0};
    pair<int, int> destination = {3, 3};

    cout << "Shortest Path: "
         << obj.shortestPath(grid, source, destination) << endl;

    return 0;
}