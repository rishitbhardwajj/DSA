#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& matrix, int row, int m) {
    for(int j = 0; j < m; j++) {
        if(matrix[row][j] != 0) {
            matrix[row][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int col, int n) {
    for(int i = 0; i < n; i++) {
        if(matrix[i][col] != 0) {
            matrix[i][col] = -1;
        }
    }
}

vector<vector<int>> method1(vector<vector<int>>& matrix, int n, int m) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(matrix[i][j] == 0) {
                markRow(matrix, i, m);
                markCol(matrix, j, n);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
vector<vector<int>> method2(vector<vector<int>>& matrix, int n, int m){
    int row[n] = {0};
    int col[m] = {0};
    for(int i =0;i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j]==0){
                row[i] =1;
                col[j]=1;
            }
        }
    }
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i]||col[j]){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> method3(vector<vector<int>> &matrix, int n, int m) {

    int col0 = 1;

    // Step 1: Mark rows and columns
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(matrix[i][j] == 0) {

                // mark row
                matrix[i][0] = 0;
int col0 = 1;
                // mark column
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Set elements to 0 based on marks
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {

            if(matrix[i][j] != 0) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Handle first row
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Handle first column
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
int main() {

    vector<vector<int>> matrix = {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1},
        {1,1,1,1}
    };
 freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> result = method2(matrix, n, m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}