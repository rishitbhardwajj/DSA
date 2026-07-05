#include<bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int n, int d){

    d = d % n;

    // Reverse first n-d elements
    reverse(arr, arr + (n-d));

    // Reverse last d elements
    reverse(arr + (n-d), arr + n);

    // Reverse whole array
    reverse(arr, arr + n);
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};

    int n = 7;
    int d = 3;

    rightRotate(arr, n, d);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}