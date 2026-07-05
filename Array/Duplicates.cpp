#include<iostream>
#include<set>
using namespace std;
//NLogn + n
int method1(int arr[],int n){
    set<int> s;
    for(int i = 0; i<n; i++){
        s.insert(arr[i]);
    }
    int index = 0;
    for(auto it: s){
        arr[index] = it;
        index++;
    }
    return index;
}
//N
int method2(int arr[], int n){
    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[j]!=arr[i]){
        arr[i+1] = arr[j];
        i++;
        }
    }
return i+1;
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
        int result = method2(arr,n);
          cout << "Array after removing duplicates:\n";

        for(int i = 0; i<result; i++){
            cout << arr[i] << " ";
        }
 return 0;
}
