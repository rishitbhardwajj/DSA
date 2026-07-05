#include <bits/stdc++.h>
using namespace std;
int method1(int arr[], int n){
    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt = 0;
        }
    }
      return maxi;
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
          cout << "MAx consecutive 1:\n";
            cout << result << " ";
        
 return 0;
}
