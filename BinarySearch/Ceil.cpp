#include <iostream>
#include <vector>
using namespace std;

int findCeil(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};

    int x;
    cout << "Enter the element: ";
    cin >> x;

    int ceilValue = findCeil(arr, x);

    if (ceilValue == -1)
        cout << "Ceil does not exist." << endl;
    else
        cout << "Ceil = " << ceilValue << endl;

    return 0;
}