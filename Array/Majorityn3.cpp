#include <bits/stdc++.h>
using namespace std;
vector<int> method1(vector<int>& nums) {
    int n = nums.size();
    vector<int> ls;

    for (int i = 0; i < n; i++) {

        // Skip if already added to the answer
        if (ls.size() == 0 || ls[0] != nums[i]) {

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            if (cnt > n / 3) {
                ls.push_back(nums[i]);
            }
        }

        // At most 2 majority elements can exist
        if (ls.size() == 2) {
            break;
        }
    }

    return ls;
}
vector<int> method2(vector<int> v) {
    vector<int> ls;
    map<int, int> mpp;

    int n = v.size();
    int mini = (n / 3) + 1;

    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;

        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }

        if (ls.size() == 2)
            break;
    }

    sort(ls.begin(), ls.end());
    return ls;
}
vector<int> method3(vector<int> v) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    // Finding potential candidates
    for (int i = 0; i < v.size(); i++) {

        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) {
            cnt1++;
        }
        else if (v[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Verify the candidates
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = (v.size() / 3) + 1;

    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    sort(ls.begin(), ls.end());
    return ls;
}
int main() {
    vector<int> v = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> ans = method2(v);

    cout << "Majority elements are: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}