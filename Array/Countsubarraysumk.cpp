#include <bits/stdc++.h>
using namespace std;

int method1(int arr[], int n, int k) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int s = 0;

            for (int x = i; x <= j; x++) {
                s += arr[x];
            }

            if (s == k) {
                cnt++;
            }
        }
    }

    return cnt;
}
int method2(int arr[], int n, int k){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int s = 0;
        for(int j = i; j<n; j++){
            s = s+arr[j];
            if(s==k ){
                cnt++;
            }
        }
    }
    return cnt;
}
int method3(vector<int>& arr, int k) {
    unordered_map<int, int> mpp;

    mpp[0] = 1;   // prefix sum 0 occurs once

    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum]++;
    }

    return cnt;
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
 freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    cout << "Number of subarrays with sum " << k << " = "
         << method2(arr, n, k);

    return 0;
}