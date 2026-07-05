#include<iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int age;
    cin >> age;
    if(age>=18) {
        cout<<"YOU ARE AN ADULT";
    }
    else{
        cout << "YOU ARE FOOL";
    }
}