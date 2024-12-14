#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n * n) ----> S.C ---> O91
int subArrXorK1(vector<int> &arr,int n,int target){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int xr = 0;
        for(int j=i;j<n;j++){
            xr = xr ^ arr[j];
            if(xr == target){
                cnt++;
            }
        }
    }
    return cnt;
}
//optimal-approach ---> T.C ---> O(n log n) ---> S.C ---> O(1);
int subArrXorK2(vector<int> &arr,int n,int target){
    map<int,int> mpp;
    int cnt = 0;
    int xr = 0;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr = xr ^ arr[i];
        int x = xr ^ target;
        cnt = cnt + mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target number : ";
    cin>>target;
    cout<<"Number of subarray with xor k is : "<<subArrXorK2(arr,n,target);
    
}