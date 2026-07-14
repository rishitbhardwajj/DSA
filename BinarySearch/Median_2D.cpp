#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            // Look for a smaller index on the left
            high = mid - 1;
        }
        else {
            // Look on the right
            low = mid + 1;
        }
    }

    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += upperBound(matrix[i], x, m);
    }

    return cnt;
}

int median(vector<vector<int>> &matrix, int n, int m) {

    n = matrix.size();
    m = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    // Find minimum and maximum element
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        int smallEqual = countSmallEqual(matrix, n, m, mid);

        if (smallEqual <= req) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << median(matrix, n, m);

    return 0;
}