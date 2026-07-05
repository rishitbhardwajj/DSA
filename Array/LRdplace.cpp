#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//o(n+d)
int method1(int arr[], int n, int d){
    d = d%n;
    int temp[d];
    for(int i = 0; i<d; i++){
    temp[i] = arr[i];
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    int j = 0;
    for(int i = n-d ; i<n; i++){
        arr[i] = temp[j];
        j++;
    }
}
//O(n+d) diff only temp push back func as i-(n-d)
int method2(int arr[], int n, int d){
    d = d%n;
    int temp[d];
    for(int i = 0; i<d; i++){
    temp[i] = arr[i];
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i = n-d ; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
}
//O(N)
int method3(int arr[], int n, int d){
    d = d%n;
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr, arr+n);
}
int main(){
     int n,d;
         freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
        cout << "Enter no of elements of array" << endl;
        cin >> n;
        cout << "Enter no of PLACES to rotate" << endl;
        cin >> d;
        int arr[n];
        cout << "Enter Array Elements"<< endl;
        for(int i = 0; i<n; i++){
            cin >> arr[i]; 
        }
        method3(arr,n,d);
          cout << "Array after rotating:\n";
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
 return 0;
}
