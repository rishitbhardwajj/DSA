#include <bits/stdc++.h>
using namespace std;
//particular element
long long method1(int n, int r) {
    if (r > n) return 0;

    r = min(r, n - r);

    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}
//find Any nth row 
void method2(int n){
    for (int c = 1; c <= n; c++) {
        cout << method1(n - 1, c - 1) << " ";
    }
}
//better nth row find approach
vector<int> method3(int n) {
    long long ans = 1;
    vector<int> row;

    row.push_back(1);

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;

        row.push_back(ans);
    }

    return row;
}

vector<vector<int>> method4(int N){
    vector<vector<int>> ans;

    for (int i = 1; i <= N; i++) {
        ans.push_back(method3(i));
    }

    return ans;
}
int main() {
    cout << method1(5, 2);  // 10
    //int n = 5;
   // method2(n);
    return 0;
}