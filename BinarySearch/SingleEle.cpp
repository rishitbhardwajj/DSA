#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
        return arr[0];

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // We are in left half
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        // We are in right half
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements (sorted array): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Single non-duplicate element is: "
         << singleNonDuplicate(arr) << endl;

    return 0;
}