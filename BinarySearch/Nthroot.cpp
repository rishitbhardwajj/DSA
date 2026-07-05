#include <iostream>
using namespace std;

// Return 1 if mid^n == m
// Return 0 if mid^n < m
// Return 2 if mid^n > m
int func(int mid, int n, int m) {
    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        ans *= mid;

        if (ans > m)
            return 2;
    }

    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);

        if (midN == 1)
            return mid;
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    int ans = NthRoot(n, m);

    if (ans == -1)
        cout << "No integer nth root exists.";
    else
        cout << "Nth Root = " << ans;

    return 0;
}