#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();
    int ind = -1;

    // Step 1: Find the breakpoint
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    // Step 2: If no breakpoint exists,
    // the array is the last permutation
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 3: Find the next greater element
    // from the right and swap
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 4: Reverse the suffix
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    A = nextGreaterPermutation(A);

    cout << "Next Permutation: ";
    for (int x : A) {
        cout << x << " ";
    }

    return 0;
}