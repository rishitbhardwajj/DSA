#include<bits/stdc++.h>
using namespace std;
int method1(int arr[], int n){
    for(int i = 1; i<n; i++){
        int flag = 0;
        for(int j = 0; j<n-1; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
                return i;
            }
    }
}
int method2(int arr[], int n){

    // Hash array
    vector<int> hash(n + 1, 0);

    // Mark present elements
    for(int i = 0; i < n-1; i++){
        hash[arr[i]] = 1;
    }

    // Find missing number
    for(int i = 1; i <= n; i++){

        if(hash[i] == 0){
            return i;
        }
    }

    return -1;
}
int method3(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n-1; i++){
        sum = sum + arr[i];
    }
    int total = n*(n+1)/2;
    int missing  = total - sum;
    return missing;
}
int method4(int arr[], int n){
    int xor1 = 0;
    for(int i = 1; i<=n; i++){
       xor1 = xor1^i;
    }
    //xor1 = xor1^(i+1)
    int xor2 = 0;
    for(int i = 0; i<n-1; i++){
        xor2 = xor2^arr[i];
    }
    return xor1^xor2;
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
        int result = method4(arr,n);
          cout << "Missing Element:\n";
            cout << result << " ";
            
        
 return 0;
}
