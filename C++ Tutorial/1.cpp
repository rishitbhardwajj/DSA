#include<iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string name, age;
   getline(cin, name);
   getline(cin, age);

    cout << name << " " << age;
}