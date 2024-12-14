#include <bits/stdc++.h>
using namespace std;

// brute-force-method --> T.C ---> O(N*N) ----> S.C ---> O(N) ---> for sorting t.c = O(N log N)
// void leadersOfArray(int arr[], int n)
// {
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         int leader = true;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] > arr[i])
//             {
//                 leader = false;
//                 break;
//             }
//         }
//         if (leader == true)
//             ans.push_back(arr[i]);
//     }
//     sort(ans.begin(), ans.end());
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
// }

// optimal approach ---> T.C ---> O(N) ---> S.C ---> O(N) ---> for sorting t.c = O(N log N)
void leadersOfArray(int arr[], int n)
{
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
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
    leadersOfArray(arr, n);
    return 0;
}