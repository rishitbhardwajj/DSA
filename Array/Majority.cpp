#include <iostream>
using namespace std;
#include <vector>
#include <map>

// Method 1: Brute Force Approach
int method1(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])
            {
                cnt++;
            }
        }

        // Check if element appears more than n/2 times
        if(cnt > n / 2)
        {
            return arr[i];
        }
    }

    return -1; // No majority element found
}

// Method 2 : Using Hash Map
int method2(vector<int> v)
{
    map<int, int> mpp;

    // Store frequency of elements
    for(int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }

    // Check majority element
    for(auto it : mpp)
    {
        if(it.second > (v.size() / 2))
        {
            return it.first;
        }
    }

    return -1;
}
int method3(vector <int> a, int n){
    int cnt = 0;
    int ele;
    for(int i = 0; i<a.size(); i++){
         if(cnt == 0){
            cnt = 1;
          ele = a[i];
         }
         else if(a[i]==ele){
            cnt++;
         }
         else{
            cnt--;
         }
    }
    int cnt1 = 0;
    for(int i = 0; i<n; i++){
        if(a[i]==ele){
            cnt1++;
        }
        if(cnt1 > a.size()/2){
            return ele;
        }
    }
    return -1;
}
//int method2
/*int main()
{
    vector<int> v = {2, 2, 3, 3, 1, 2, 2};

    int ans = method3(v);
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    if(ans != -1)
        cout << "Majority Element = " << ans;
    else
        cout << "No Majority Element";

    return 0;
}*/
//M1
int main()
{
    int arr[] = {2, 2, 3, 3, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int ans = method1(arr, n);

    if(ans != -1)
        cout << "Majority Element = " << ans;
    else
        cout << "No Majority Element";

    return 0;
}