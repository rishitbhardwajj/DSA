#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }

    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        totalH += ceil((double)v[i] / (double)hourly);
    }

    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);

        if (totalH <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile:\n";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter total hours: ";
    cin >> h;

    cout << "Minimum eating speed = "
         << minimumRateToEatBananas(piles, h) << endl;

    return 0;
}