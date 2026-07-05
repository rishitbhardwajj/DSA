#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n ) {
    int flag = 0;
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
           return false;
          
        }
    }
    return true;
}
int main() {
        int n;
         freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
        cout << "Enter no of elements of array" << endl;
        cin >> n;
        int arr[n];
        cout << "Enter Array Elements"<< endl;
        for(int i = 0; i<n; i++){
            cin >> arr[i]; 
        }
       bool result = isSorted(arr, n);

    if(result){

        cout << "Array is Sorted";
    }
    else{

        cout << "Array is NOT Sorted";
    }

    return 0;
}
