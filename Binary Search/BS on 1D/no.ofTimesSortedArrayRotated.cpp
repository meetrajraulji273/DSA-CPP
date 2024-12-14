#include<bits/stdc++.h>
using namespace std;

//optimal-approach ---> T.C ---> O(log 2 n) ----> S.C ---> O(1)
int numberOfTimesSortedArrayRotated(vector<int> &arr,int n){
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
    int idx = -1;
    int low = 0;int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans = arr[low];
                idx = low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans = arr[low];
                idx = low;
            }
            low = mid + 1;
        }else{
            if(arr[mid]<ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    return idx;
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
    cout<<"The number of times the array has rotated is "<<numberOfTimesSortedArrayRotated(arr,n);
    return 0;
}