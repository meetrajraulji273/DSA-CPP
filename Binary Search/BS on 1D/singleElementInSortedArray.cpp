#include<bits/stdc++.h>
using namespace std;

//brute-force method ---> T.C ---> O(n) ---> S.C ---> O(1);
int singleElementInSortedArray1(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]!=arr[i+1]) return arr[i];
        }else if(i=n-1){
            if(arr[i]!=arr[i-1]) return arr[i];
        }else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]) return arr[i];
        }
    }
    return -1;
}

//optimal-approach ---> T.C ----> O(log 2 n) ----> S.C ----> O(1)
int singleElementInSortedArray2(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
    int low = 0;int high = n-1;
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    while(low<=high){
        int mid = low + (high -low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        if((mid%2 == 1 && arr[mid-1]==arr[mid])||(mid%2==0 && arr[mid]==arr[mid+1])){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
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
    cout<<endl;
    cout<<"The single element in the sorted array is : "<<singleElementInSortedArray1(arr,n);
}