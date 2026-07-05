#include <iostream>
#include <vector>
using namespace std;

// Move all zeros to end
void method1(int arr[], int n) {

    vector<int> temp;

    // Step 1: Store non-zero elements
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    // Number of non-zero elements
    int nz = temp.size();

    // Step 2: Put non-zero elements back
    for(int i = 0; i < nz; i++) {
        arr[i] = temp[i];
    }

    // Step 3: Fill remaining places with 0
    for(int i = nz; i < n; i++) {
        arr[i] = 0;
    }
}
int method2(int arr[], int n){
    int j =-1;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i = j+1; i<n; i++){
 if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main() {
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    int arr[] = {1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    method2(arr, n);

    cout << "Array after moving zeros:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}