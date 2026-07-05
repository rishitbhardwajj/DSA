#include<iostream>
using namespace std;
void doSomething(int &num) {

    cout << num << endl;

    num += 5;

    cout << num << endl;

    num += 5;

    cout << num << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num = 10;

    doSomething(num);

    cout << num << endl;

    return 0;
}