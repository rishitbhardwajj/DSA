#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Search space is already sorted
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted
        else {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum element is: " << findMin(arr) << endl;

    return 0;
}