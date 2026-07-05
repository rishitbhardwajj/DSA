#include <iostream>
#include <vector>
using namespace std;

// Brute Force Solution for Intersection of 2 Sorted Arrays
vector<int> intersectionArray(vector<int> a, vector<int> b){

    int n1 = a.size();
    int n2 = b.size();

    vector<int> ans;

    // Visited array for second array
    vector<int> vis(n2, 0);

    for(int i = 0; i < n1; i++){

        for(int j = 0; j < n2; j++){

            // If elements match and not already used
            if(a[i] == b[j] && vis[j] == 0){

                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            // Since arrays are sorted
            if(b[j] > a[i]){
                break;
            }
        }
    }

    return ans;
}

int main(){

    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};

    vector<int> result = intersectionArray(a, b);

    cout << "Intersection Array:\n";

    for(auto it : result){
        cout << it << " ";
    }

    return 0;
}