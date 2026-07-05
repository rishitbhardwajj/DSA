#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinIndex(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If all three are equal, we can't decide the sorted half
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int index = findMinIndex(arr);

    cout << "Index of minimum element: " << index << endl;
    cout << "Minimum element: " << arr[index] << endl;

    return 0;
}