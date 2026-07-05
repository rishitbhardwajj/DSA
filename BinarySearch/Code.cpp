#include <bits/stdc++.h>
using namespace std;

int method1(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low+high)/ 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int method2(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return method2(arr, low, mid - 1, key);

    return method2(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int key = 3;
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int result = method1(arr, n, key);

    cout << result;

    return 0;
}