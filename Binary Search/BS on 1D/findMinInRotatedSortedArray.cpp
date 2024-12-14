#include<bits/stdc++.h>
using namespace std;

// optimal-approach ---> T.C ---> o(log 2 N) ----> S.C ----> O(1)
int findMinInRotatedSortedArray(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low = 0;int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans = arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans = arr[low];
            }
            low = mid + 1;
        }else{
            if(arr[mid]<ans){
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return ans;
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
    cout<<"The minimum number in the rotated sorted array is : "<<findMinInRotatedSortedArray(arr,n);
    return 0;
}