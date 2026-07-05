#include<bits/stdc++.h>
using namespace std;

void method1(int arr[], int n)
{
    vector<int> pos, neg;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    for(int i = 0; i < n/2; i++)
    {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
}
void method2(int arr[], int n)
{
    int ans[n];

    int posindex = 0;
    int negindex = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            ans[posindex] = arr[i];
            posindex += 2;
        }
        else
        {
            ans[negindex] = arr[i];
            negindex += 2;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
//unequal sign 
void method3(int arr[], int n){
     vector<int> pos, neg;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
if(pos.size()>neg.size()){
    for(int i = 0; i < neg.size(); i++)
    {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    int index = neg.size()*2;
    for(int i = neg.size(); i<pos.size(); i++){
        arr[index] = pos[i];
        index++;
    }
}
}
int main(){
    int arr[] = {-1,2,3,4,-3,1};
    int n = 6;
freopen("input.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    method3(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}