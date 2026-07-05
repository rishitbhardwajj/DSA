#include <bits/stdc++.h>
using namespace std;
int method1(int arr[], int n, int k){
    for(int i = 0; i<n; i++){
        int s = 0,len = 0;
        for(int j = i; j<n; j++){
            s = s+arr[j];
            if(s==k ){
                len = max(len,j-i+1);
            }
        }
        return len;
    }
}
int method2(vector<int> a, long long n, long long k) {

    map<long long, int> preSumMap;
   long long n = a.size();
    long long sum = 0;

    int maxLen = 0;

    for(int i = 0; i < n; i++) {

        sum += a[i];

        if(sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        if(preSumMap.find(rem) != preSumMap.end()) {

            int len = i - preSumMap[rem];

            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()) {

            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
int method3(vector<int> a, long long n, long long k){
    int left=0,right=0;
    long long sum=a[0];
    int maxLen=0;
    long long n = a.size();

    while(right<n){

        while(left<=right && sum>k){
            sum-=a[left];
            left++;
        }

        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }

        right++;

        if(right<n){
            sum+=a[right];
        }
    }

    return maxLen;
}
int main(){
    long long n,k;
         freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
        cout << "Enter no of elements of array" << endl;
        cin >> n;
        cin>>k;
        int arr[n];
        cout << "Enter Array Elements"<< endl;
        for(int i = 0; i<n; i++){
            cin >> arr[i]; 
        }
        int result = method1(arr,n,k);
          cout << "max lenghth of subarray:\n";
            cout << result << " ";
            
        
 return 0;
}
