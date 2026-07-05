#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;   // Stores the floor value

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = arr[mid];      // Possible floor
            low = mid + 1;       // Look for a larger valid floor
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};

    int x;
    cout << "Enter element: ";
    cin >> x;

    int floorValue = findFloor(arr, x);

    if (floorValue == -1)
        cout << "Floor does not exist." << endl;
    else
        cout << "Floor = " << floorValue << endl;

    return 0;
}