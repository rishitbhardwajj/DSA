#include<bits/stdc++.h>
using namespace std;
//N
int method1(int arr[], int n){
int temp = arr[0];
for(int i = 1; i<n; i++){
    arr[i-1] = arr[i];
}
arr[n-1] = temp;
}
int main(){
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
        int result = method1(arr,n);
          cout << "Array after rotating:\n";
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
 return 0;
}
