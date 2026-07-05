#include <iostream>
#include <vector>
using namespace std;

int method1(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Maybe this is the answer
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;   // Look for a smaller index on the left
        }
        else {
            low = mid + 1;    // Search on the right
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();

    int x;
    cout << "Enter the element: ";
    cin >> x;

    int index = method1(arr, n, x);

    if (index == n)
        cout << "Lower Bound does not exist." << endl;
    else
        cout << "Lower Bound index = " << index
             << "\nValue = " << arr[index] << endl;

    return 0;
}