#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid,
         vector<vector<int>>& vis, int row0, int col0,
         vector<pair<int, int>>& vec) {

    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, +1};

    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
           !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfs(nrow, ncol, grid, vis, row0, col0, vec);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int, int>> vec;
                dfs(i, j, grid, vis, i, j, vec);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countDistinctIslands(grid) << endl;

    return 0;
}