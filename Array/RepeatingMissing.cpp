#include<bits/stdc++.h>
using namespace std;

pair<int,int> method1(int arr[], int n)
{
    int repeating = -1;
    int missing = -1;

    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == i)
            {
                cnt++;
            }
        }

        if(cnt == 2)
        {
            repeating = i;
        }

        if(cnt == 0)
        {
            missing = i;
        }

        // Stop if both are found
        if(repeating != -1 && missing != -1)
        {
            break;
        }
    }

    return {repeating, missing};
}
pair<int,int> findMissingRepeating(vector<int>& arr, int n)
{
    long long s = 0, p = 0;

    for(int i = 0; i < n; i++)
    {
        s += arr[i];
        p += 1LL * arr[i] * arr[i];
    }

    long long S = 1LL * n * (n + 1) / 2;
    long long P = 1LL * n * (n + 1) * (2*n + 1) / 6;

    long long x = s - S;           // R - M
    long long y = (p - P) / x;     // R + M

    int R = (x + y) / 2;
    int M = y - R;

    return {R, M};
}

pair<int,int> findMissingRepeatingNumbers(int arr[], int n)
{
    int xr = 0;

    // XOR of array elements
    for(int i = 0; i < n; i++)
    {
        xr ^= arr[i];
    }

    // XOR of 1 to n
    for(int i = 1; i <= n; i++)
    {
        xr ^= i;
    }

    // Rightmost set bit
    int bitNo = xr & ~(xr - 1);

    int zero = 0;
    int one = 0;

    // Divide array elements into two groups
    for(int i = 0; i < n; i++)
    {
        if((arr[i] & bitNo) != 0)
            one ^= arr[i];
        else
            zero ^= arr[i];
    }

    // Divide numbers 1 to n into two groups
    for(int i = 1; i <= n; i++)
    {
        if((i & bitNo) != 0)
            one ^= i;
        else
            zero ^= i;
    }

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == zero)
            cnt++;
    }

    if(cnt == 2)
        return {zero, one}; // {repeating, missing}

    return {one, zero};
}

int main()
{
    int arr[] = {4,3,6,2,1,1};
    int n = 6;

    pair<int,int> result = method1(arr, n);

    cout << "Repeating = " << result.first << endl;
    cout << "Missing = " << result.second << endl;

    return 0;
}