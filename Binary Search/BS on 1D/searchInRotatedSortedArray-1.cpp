#include<bits/stdc++.h>
using namespace std;

//optimal-approach ---> T.C ---> O(log 2 N) ---> S.C ---> O(1)
int searchInRotatedSortedArray(vector<int> &arr,int n,int target){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low = 0;int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target) return mid;
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid]<=target && target<=arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
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
    int target;
    cout<<"Enter the target number : ";
    cin>>target;
    cout<<"The index of the targeted number is : "<<searchInRotatedSortedArray(arr,n,target);
    return 0;
}