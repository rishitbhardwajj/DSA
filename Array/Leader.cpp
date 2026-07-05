#include<bits/stdc++.h>
using namespace std;

vector<int> method1(int arr[], int n) {
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        bool leader = true;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }

        if(leader) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
vector<int> method2(int arr[], int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    sort(ans.begin(), ans.end());
      return ans;
}
int main() {
    int arr[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
 freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    vector<int> ans = method2(arr, n);

    cout << "Leaders: ";
    for(int x : ans)
        cout << x << " ";

    return 0;
}