#include<bits/stdc++.h>
using namespace std;

int countSubarrayWithSumK(vector<int> &arr,int k,int n){
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int prefixSum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        prefixSum = prefixSum + arr[i];
        int remaining = prefixSum - k;
        count = count + mpp[remaining];
        mpp[prefixSum] += 1;
    }
    return count;
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
    int k;
    cout<<"Enter the value of k : ";
    cin>>k;
    cout<<"Number of subarrays with sum k is : "<<countSubarrayWithSumK(arr,k,n);
    return 0;
}