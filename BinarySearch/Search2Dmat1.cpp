#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n * m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int target;
    cin >> target;

    if (searchMatrix(mat, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}