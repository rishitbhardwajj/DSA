#include <bits/stdc++.h>
using namespace std;

int method1(int arr[], int n)
{
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            // compare with current subarray sum
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

//Kadanes Alogorithm
int method2(int arr[], int n)
{
    long long sum = 0, maxi = LLONG_MIN;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum > maxi)
        {
            maxi = sum;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

//printing subarray with max sum 
int method3(int arr[], int n)
{
    long long sum = 0, maxi = LLONG_MIN;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for(int i = 0; i < n; i++)
    {
        // Start new subarray
        if(sum == 0)
        {
            start = i;
        }

        sum += arr[i];

        // Update maximum sum
        if(sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // Reset if sum becomes negative
        if(sum < 0)
        {
            sum = 0;
        }
    }

    // Print subarray
    cout << "Maximum Subarray: ";

    for(int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return maxi;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    int n = sizeof(arr) / sizeof(arr[0]);
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int ans = method2(arr, n);

    cout << "Maximum Subarray Sum = " << ans;

    return 0;
}