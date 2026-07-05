#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> method1(vector<vector<int>> &matrix, int n) {

    vector<vector<int>> ans(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    return ans;
}
vector<vector<int>> method2(vector<vector<int>> &matrix, int n) {

    // Step 1: Transpose
    for(int i = 0; i < n-2; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main() {

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> rotated = method1(matrix, n);

    // Print rotated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}