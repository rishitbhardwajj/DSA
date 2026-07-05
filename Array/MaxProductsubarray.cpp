#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int prod = 1;

        for(int j = i; j < n; j++)
        {
            prod *= nums[j];
            maxi = max(maxi, prod);
        }
    }

    return maxi;
}
#include <bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr) {
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        if (pre == 0)
            pre = 1;

        if (suff == 0)
            suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];

        ans = max(ans, max(pre, suff));
    }

    return ans;
}
int main()
{
    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product = " << maxProduct(nums);

    return 0;
}