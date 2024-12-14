#include <bits/stdc++.h>
using namespace std;

// brute-force-method -->T.C. ---> o(n+n) ---> S.C --> o(n)
//  void rearrangeTheElementsBySign(int arr[],int n){
//      vector<int> pos;
//      vector<int> neg;
//      for(int i=0;i<n;i++){
//          if(arr[i]>0){
//              pos.push_back(arr[i]);
//          }else{
//              neg.push_back(arr[i]);
//          }
//      }
//      int ans[n];
//      for(int i=0;i<n/2;i++){
//          ans[2*i] = pos[i];
//          ans[2*i+1] = neg[i];
//      }
//      for(int i=0;i<n;i++){
//          cout<<ans[i]<<" ";
//      }
//  }

// optimal approach --> T.C --> o(n) S.C --> o(n)
// void rearrangeTheElementsBySign(int arr[],int n){
//     int posIdx = 0;
//     int negIdx = 1;
//     int ans[n];
//     for(int i=0;i<n;i++){
//         if(arr[i]>0){
//             ans[posIdx] = arr[i];
//             posIdx += 2;
//         }else{
//             ans[negIdx] = arr[i];
//             negIdx += 2;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<ans[i]<<" ";
//     }
// }

// variety approach
void rearrangeTheElementsBySign(int arr[], int n)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        int l1 = 2 * neg.size() + pos.size() - neg.size();
        int ans[l1];
        for (int i = 0; i < 2 * neg.size(); i++)
        {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }
        int idx = 2 * neg.size();
        for (int i = idx; i < pos.size(); i++)
        {
            ans[i] = pos[i];
        }
        for(int i=0;i<l1;i++){
            cout<<ans[i]<<" ";
        }
    }
    else
    {
        int l2 = 2 * pos.size() + neg.size() - pos.size();
        int ans[l2];
        for (int i = 0; i < 2 * pos.size(); i++)
        {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }
        int idx = 2 * pos.size();
        for (int i = idx; i < neg.size(); i++)
        {
            ans[i] = neg[i];
        }
        for(int i=0;i<l2;i++){
            cout<<ans[i]<<" ";
        }
    }

    
}

int main()
{
    int n;
    cout << "Enter any even strength of the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element arr[" << i << "] : ";
        cin >> arr[i];
    }
    rearrangeTheElementsBySign(arr, n);
}