#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionArray(vector<int> a, vector<int> b){

    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;

    vector<int> ans;

    while(i < n1 && j < n2){

        // If first array element is smaller
        if(a[i] < b[j]){
            i++;
        }

        // If second array element is smaller
        else if(b[j] < a[i]){
            j++;
        }

        // If both are equal
        else{

            ans.push_back(a[i]);

            i++;
            j++;
        }
    }

    return ans;
}

int main(){

    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};
 freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    vector<int> result = intersectionArray(a, b);

    cout << "Intersection Array:\n";

    for(auto it : result){
        cout << it << " ";
    }

    return 0;
}