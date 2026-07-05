#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
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
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
            METHOD 2
    int x;
    cout << "Enter element: ";
    cin >> x;

    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (lb == arr.size()) {
        cout << "Lower Bound does not exist." << endl;
    } else {
        cout << "Lower Bound Index = " << lb << endl;
        cout << "Lower Bound Value = " << arr[lb] << endl;
    }

    return 0;
}*/
int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();

    int x;
    cout << "Enter the element: ";
    cin >> x;

    int index = lowerBound(arr, n, x);

    if (index == n)
        cout << "Lower Bound does not exist." << endl;
    else
        cout << "Lower Bound index = " << index
             << "\nValue = " << arr[index] << endl;

    return 0;
}