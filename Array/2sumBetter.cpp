#include<bits/stdc++.h>
using namespace std;

pair<int,int> method2(int arr[], int n, int target){

    map<int,int> mpp;

    for(int i = 0; i < n; i++){

        int a = arr[i];

        int more = target - a;

        if(mpp.find(more) != mpp.end()){

            return {mpp[more], i};
        }

        mpp[a] = i;
    }

    return {-1,-1};
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int arr[] = {2,6,5,8,11};

    int n = 5;

    int target = 14;

    pair<int,int> ans = method2(arr,n,target);

    cout << ans.first << " "
         << ans.second;

    return 0;
}