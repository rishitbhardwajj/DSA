#include<bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target){

    int left = 0, right = n - 1;

    sort(book.begin(), book.end());

    while(left < right){

        int sum = book[left] + book[right];

        if(sum == target){

            return "YES";
        }

        else if(sum < target){

            left++;
        }

        else{

            right--;
        }
    }

    return "NO";
}

int main(){

    int n,target;
 freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);

    cin >> n;

    cin >> target;

    vector<int> book(n);

    for(int i = 0; i < n; i++){

        cin >> book[i];
    }

    cout << read(n,book,target);

    return 0;
}