#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr,int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid  = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1; 
        }else{
            low = mid + 1;
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
    int target;
    cout<<"Enter the target number which you want to insert : ";
    cin>>target;
    cout<<"The index at which the number has to be inserted in the sorted array is : "<<searchInsert(arr,target);
    return 0;
}