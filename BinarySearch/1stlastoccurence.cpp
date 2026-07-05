#include <bits/stdc++.h>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Maybe this is the answer
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;   // Look for a smaller index on the left
        }
        else {
            low = mid + 1;    // Search on the right
        }
    }

    return ans;
}
int UpperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Maybe this is the answer
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;   // Look for a smaller index on the left
        }
        else {
            low = mid + 1;    // Search on the right
        }
    }

    return ans;
}
pair<int,int>method1(vector<int>&arr, int n, int k){
    int lb = lowerBound(arr,n,k);
    if(lb==n||arr[lb]!=k) return {-1,-1};
    return {lb,UpperBound(arr,n,k)-1};
}
/*#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return last;
}pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);

    if (first == -1)
        return {-1, -1};

    int last = lastOccurrence(arr, n, k);

    return {first, last};
}*/
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6};

    int n = arr.size();

    int k;
    cout << "Enter element to search: ";
    cin >> k;

    pair<int, int> ans = method1(arr, n, k);

    cout << "First Occurrence Index = " << ans.first << endl;
    cout << "Last Occurrence Index = " << ans.second << endl;

    return 0;
}