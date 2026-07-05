#include<bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(int arr[],int n,int target){

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            if(arr[i]+arr[j]==target){

                return {i,j};
            }
        }
    }

    return {-1,-1};
}

int main(){

    int arr[]={2,6,5,8,11};
    freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int n=5;

    int target=14;

    pair<int,int> ans=twoSum(arr,n,target);

    cout<<"Indices are: "
        <<ans.first<<" "
        <<ans.second;

    return 0;
}