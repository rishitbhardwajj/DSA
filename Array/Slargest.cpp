#include<bits/stdc++.h>
using namespace std;
//NLOGN+N
int method1(int arr[], int n){

    cout << "Sorting the array\n";

    // Bubble Sort
    for(int i = 0; i < n; i++){

        int flag = 0;

        for(int j = 0; j < n-1-i; j++){

            if(arr[j] > arr[j+1]){

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                flag = 1;
            }
        }

        if(flag == 0){
            cout << "NO SWAPPING\n";
            break;
        }
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    int largest = arr[n-1];

    int slargest = -1;

    // Finding second largest
    for(int i = n-2; i >= 0; i--){

        if(arr[i] != largest){

            slargest = arr[i];
            break;
        }
    }

    return slargest;
}
//n
int method2(int arr[], int n) {

    int largest = arr[0];

    // Find largest
    for(int i = 0; i < n; i++) {

        if(arr[i] > largest) {

            largest = arr[i];
        }
    }

    int slargest = -1;

    // Find second largest
    for(int i = 0; i < n; i++) {

        if(arr[i] > slargest && arr[i] != largest) {

            slargest = arr[i];
        }
    }

    return slargest;
}
//N
int method3(int arr[], int n) {
    int largest = arr[0];
    int slargest = -1;
    for(int i = 0; i<n; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>slargest && arr[i]<largest){
            slargest = arr[i];
        }
    }
    return slargest;
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
        int result = method3(arr,n);
        cout << "2nd Largest Value: = " << result << endl;
        return 0;
    }
    /*SIMILARLY DO FOR Ssmallest ONE bss ssmallest take it int max and reverse the order the compare operators*/
    