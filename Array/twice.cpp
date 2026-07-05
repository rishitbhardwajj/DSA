#include<bits/stdc++.h>
using namespace std;

int method1(int arr[], int n){

    int cnt, num;

    for(int i = 0; i < n; i++){

        num = arr[i];
        cnt = 0;

        for(int j = 0; j < n; j++){

            if(arr[j] == num){
                cnt++;
            }
        }

        if(cnt == 1){
            return num;
        }
    }

    return -1;
}
int method2(int arr[], int n){

    // Hash array
    int hash[100] = {0};

    // Store frequencies
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    // Find element occurring once
    for(int i = 0; i < n; i++){

        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }

    return -1;
}
int method2(int arr[], int n){

    map<int,int> mpp;

    // Store frequencies
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // Find element occurring once
    for(int i = 0; i < n; i++){

        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }

    return -1;
}
int method3(int arr[], int n){

    map<int,int> mpp;

    // Store frequencies
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // Find element occurring once
    for(int i = 0; i < n; i++){

        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }

    return -1;
}
int method4(int arr[], int n){

    int xorr = 0;

    // XOR all array elements
    for(int i = 0; i < n; i++){
        xorr = xorr ^ arr[i];
    }

    return xorr;
}
int main(){

    int n;

    freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int result = method1(arr, n);

    cout << result;

    return 0;
}
 