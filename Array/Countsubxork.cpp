#include <bits/stdc++.h>
using namespace std;

int countSubarraysXOR(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int xr = 0;

        for (int j = i; j < n; j++) {
            xr ^= arr[j];

            if (xr == k)
                cnt++;
        }
    }

    return cnt;
}
int subarraysWithSumK(vector<int> a, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;      // mpp[0] = 1
    int cnt = 0;

    for(int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];

        int x = xr ^ k;
        cnt += mpp[x];

        mpp[xr]++;
    }

    return cnt;
}
int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of K: ";
    cin >> k;

    cout << "Count of subarrays with XOR = " << k << " is: "
         << countSubarraysXOR(arr, k) << endl;

    return 0;
}