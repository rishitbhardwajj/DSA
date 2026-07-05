#include<iostream>
using namespace std;
    void printname(string name) {
        cout << "HELLO" << name;
    }
    int sum(int num1, int num2){
        int result = num1 + num2;
        return result;
    }
    
    int main() {
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num1 , num2;
    cin >> num1 >> num2 ;
    int res = sum(num1, num2);
    cout << res;
        string name;
        getline( cin, name);
        printname(name);
    }