#include <iostream>
#include <set>
#include <vector>
using namespace std;

void method1(int arr1[], int arr2[], int n1, int n2){

    set<int> s;

    // Insert first array
    for(int i = 0; i < n1; i++){
        s.insert(arr1[i]);
    }

    // Insert second array
    for(int i = 0; i < n2; i++){
        s.insert(arr2[i]);
    }

    cout << "Union Array:\n";

    for(auto it : s){
        cout << it << " ";
    }
}
vector<int> sortedarray(vector<int> a, vector<int> b){

    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;

    vector<int> unionarray;

    // Traverse both arrays
    while(i < n1 && j < n2){

        if(a[i] <= b[j]){

            if(unionarray.size() == 0 || unionarray.back() != a[i]){
                unionarray.push_back(a[i]);
            }

            i++;
        }

        else{

            if(unionarray.size() == 0 || unionarray.back() != b[j]){
                unionarray.push_back(b[j]);
            }

            j++;
        }
    }

    // Remaining elements of a
    while(i < n1){

        if(unionarray.size() == 0 || unionarray.back() != a[i]){
            unionarray.push_back(a[i]);
        }

        i++;
    }

    // Remaining elements of b
    while(j < n2){

        if(unionarray.size() == 0 || unionarray.back() != b[j]){
            unionarray.push_back(b[j]);
        }

        j++;
    }

    return unionarray;
}

int main() {

    int n1, n2;

    freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    cout << "Enter n1 and n2\n";

    cin >> n1 >> n2;

    int arr1[n1], arr2[n2];

    cout << "Enter first array\n";

    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    cout << "Enter second array\n";

    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    method1(arr1, arr2, n1, n2);
vector<int> a = {1,1,2,3,4,5};
    vector<int> b = {2,3,4,4,5,6};

    vector<int> result = sortedarray(a, b);

    cout << "Union Array:\n";

    for(auto it : result){
        cout << it << " ";
    }

    return 0;
}