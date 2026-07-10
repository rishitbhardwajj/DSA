#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int cnt = 0;

    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = (arr[i] - arr[i - 1]) / dist;

        if ((arr[i] - arr[i - 1]) == numberInBetween * dist) {
            numberInBetween--;
        }

        cnt += numberInBetween;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;

    while (high - low > diff) {
        long double mid = (low + high) / 2.0;

        int cnt = numberOfGasStationsRequired(mid, arr);

        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}
/*long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++) {
        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second;
        howMany[secInd]++;

        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen =
            iniDiff / (long double)(howMany[secInd] + 1);

        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}*/
int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << fixed << setprecision(6)
         << minimiseMaxDistance(arr, k);

    return 0;
}