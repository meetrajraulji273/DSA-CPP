#include <bits/stdc++.h>
using namespace std;

//brute-force method  ---> T.C ---> O(N! * N)  ---> S.C ---> O(1)

//better approach ---> T.C ---> O(N! * N)  ---> S.C ---> O(1)
void next_permutation(int arr[],int n){
    
    next_permutation(arr[0],arr[n]);
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

//optimal approach ---> T.C  --> o(3N) ---> S.C ---> o(1)
void next_permutation(int arr[], int n)
{
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }
    for (int i = n - 1; i > idx; i--)
    {
        if (arr[i] > arr[idx])
        {
            swap(arr[i], arr[i + 1]);
            break;
        }
    }
    reverse(arr[idx+1],arr[n]);
    if (idx == -1)
        reverse(arr[0], arr[n]);
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

int main()
{
    int n;
    cout << "Enter the strength of the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element arr[" << i << "] : ";
        cin >> arr[i];
    }
    next_permutation(arr, n);
    return 0;
}