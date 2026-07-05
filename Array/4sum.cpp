#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> method1(vector<int>& nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> method2(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            set<long long> hashset;

            for (int k = j + 1; k < n; k++) {

                long long sum = nums[i] + nums[j];
                sum += nums[k];

                long long fourth = target - sum;

                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashset.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans = method2(nums, target);

    cout << "\nQuadruplets:\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
