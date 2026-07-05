#include<iostream>
using namespace std;

// pass by reference
void doSomething(int arr[], int n) {

    arr[0] += 100;

    cout << "Value inside function: " << arr[0] << endl;
}

int main() {
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 5;

    int arr[n];

    for(int i = 0; i < n; i = i + 1) {
        cin >> arr[i];
    }

    doSomething(arr, n);

    cout << "Value inside int main: " << arr[0] << endl;

    return 0;
}