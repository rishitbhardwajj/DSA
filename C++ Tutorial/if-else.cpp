#include<iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int age;
    cin >> age;

    if(age < 18) {
        cout << "not eligible for job";
    }

    // >= 18
    else if(age <= 57) {
        cout << "eligible for job";

        if(age >= 55) {
            cout << ", but retirement soon";
        }
    }

    else {
        cout << "retirement time";
    }

   
}