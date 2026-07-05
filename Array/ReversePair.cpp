#include <bits/stdc++.h>
using namespace std;

int reversePairs(int arr[], int n)
{
    int cnt = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > 2 * arr[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for(int i = low; i <= mid; i++)
    {
        while(right <= high && arr[i] > 2LL * arr[right])
        {
            right++;
        }

        cnt += (right - (mid + 1));
    }

    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &arr, int low, int high)
{
    if(low >= high)
        return 0;

    int mid = (low + high) / 2;

    int cnt = 0;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    cnt += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return cnt;
}

int reversePairs(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Number of reverse pairs = "
         << reversePairs(arr, n);

    return 0;
}