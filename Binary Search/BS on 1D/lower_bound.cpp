#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n) ---> S.C ---> O(1)
int lower_bound1(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=target){
            return i;
        }
    }
    return -1;
}

//using c++ stl ----> lower_bound function
int lower_bound2(vector<int> &arr,int target){
    //here the lower_bound function for vector will return the iterator of the target in the array
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto lb_it = lower_bound(arr.begin(),arr.end(),target);
    int lb_idx = lb_it - arr.begin();
    return lb_idx; 
}   

//optimal-approach ---> T.C ---> O(log 2 N) ---> S.C ---> O(1)
int lower_bound3(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low = 0;
    int  high = arr.size() - 1;
    int ans = arr.size();
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }else if(arr[mid] < target){
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
    cout<<"Enter the target number : ";
    cin>>target;
    cout<<"The smallet index in the array at which number is greater than or equal to the target is : "<<lower_bound2(arr,target);
    return 0;
}