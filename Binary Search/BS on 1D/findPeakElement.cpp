#include<bits/stdc++.h>
using namespace std;

//brute-force method ----> T.C -----> O(n) ----> S.C ----> O(1);
int findPeakElement1(vector<int> &arr,int n){
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])){
            return i;
        }
    }
    return -1;
}

//this will return any one index of the peak element in case of multiple peak element
//optimal-approach ---> T.C ----> O(log 2 n) ----> S.C ----> O(1)
int findPeakElement2(vector<int> &arr,int n){
    for(auto it : arr){     
        cout<<it<<" ";
    }
    cout<<endl;
    int low = 1;
    int high = n-2;
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    while(low<=high){
        int mid = low + (high -low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        if(arr[mid-1]<arr[mid]) low = mid + 1;
        else if(arr[mid+1]<arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
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
    cout<<"The index of the peak element in the array is : "<<findPeakElement1(arr,n);
    return 0;
}