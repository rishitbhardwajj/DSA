#include<bits/stdc++.h>
using namespace std;
//NLOGN
int method1(int arr[], int n){
    cout << "Sorting the array";
    for(int i = 0; i<n; i++){
        int flag = 0;
        for(int j = 0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
         if(flag == 0){
                cout << "NO SWAPPING";
                break;
        }
        cout << "Sorted Array";
        for(int i = 0; i<n; i++){
            cout << arr[i];
        }
        int largest = arr[n-1];
        return largest;
    }
}
//N
int method2(int arr[],int n){
    int largest = arr[0];
     for(int i = 0; i<n; i++){
            if(arr[i]>largest){
                largest = arr[i];
                
        
}
}
return largest;
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
        int result = method2(arr,n);
        cout << "Largest Value: = " << result << endl;
        return 0;
    }
    
