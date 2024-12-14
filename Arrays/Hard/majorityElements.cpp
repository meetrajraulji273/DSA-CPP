#include <bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n * n) ---> S.C ----> O(1);
void majorityElements1(int arr[], int n)
{
    vector<int> ls;
    for (int i = 0; i < n; i++)
    {
        if (ls.size() == 0 || ls[0] != arr[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > n / 3)
            {
                ls.push_back(arr[i]);
            }
        }
        if(ls.size() == 2){
            break;
        }
    }
    for (auto it : ls)
    {
        cout << it << " ";
    }
}

//better-approach --> T.C ---> O(n) ---> S.C ---> O(n)
void majorityElements2(int arr[],int n){
    unordered_map<int,int> mpp;
    int min = n/3 + 1;
    vector<int> ls;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == min){
            ls.push_back(arr[i]);
        }
        if(ls.size() == 2){
            break;
        }
    }
    for(auto it : ls){
        cout<<it<<" " ;
    }
}

//optimal-approach ---> T.C ---> O(n * n) ----> S.C. ---> O(1)
void majorityElements3(int arr[],int n) {
        int cnt1 = 0;int el1 = INT_MIN;
        int cnt2 = 0;int el2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && arr[i]!=el2){
                cnt1 =1;
                el1 = arr[i];
            }else if(cnt2 == 0 && arr[i]!=el1){
                cnt2 = 1;
                el2 = arr[i];
            }else if(arr[i] == el1){
                cnt1++;
            }else if(arr[i] == el2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(el1 == arr[i]) cnt1++;
            if(el2 == arr[i]) cnt2++; 
        }
        int min = n/3 + 1;
        if(cnt1 >= min) ans.push_back(el1);
        if(cnt2 >= min) ans.push_back(el2);

        for(auto it : ans){
            cout<<it<<" ";
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
    majorityElements3(arr, n);
    return 0;
}