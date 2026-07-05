#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    int low = 1, high = n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if (val <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Floor square root = 0";
        return 0;
    }

    cout << "Floor square root = " << floorSqrt(n);

    return 0;
}