#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}