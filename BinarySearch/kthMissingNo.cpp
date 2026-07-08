#include <iostream>
#include <vector>
using namespace std;

int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);

        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return k + high + 1;
}

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "The " << k << "th missing positive number is: "
         << missingK(vec, n, k) << endl;

    return 0;
}