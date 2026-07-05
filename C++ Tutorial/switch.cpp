#include<iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int day;
    cin >> day;
    switch(day) {
        case 1:
             cout << "MONDAY";
             break;
        case 2:
        cout << "TUESDAY";
        break;
        case 3:
        cout << "WEDNESDAY";
        break;
        case 4:
        cout << "THURSDAY";
        break;
        case 5:
        cout << "FRIDAY";
        break;
        case 6:
        cout << " Saturday" << endl;
        break;
        case 7:
        cout << "Sunday";
        break;
        default:
        cout << "Invalid check";
        break;
    
    }
cout << "COMPLETE";
}
