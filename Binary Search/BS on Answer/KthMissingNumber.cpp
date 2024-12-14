#include<bits/stdc++.h>
using namespace std;

//brute-force method --> T.C ---> O(n) ---> S.C ---> O(1)
int KthMissingNumber1(vector<int> &arr,int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
}

//optimal-approach ---> T.C ---> O(log 2 n) ---> S.C ---> O(1)
int KthMissingNumber2(vector<int> &arr,int k){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return high + 1 + k;
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
    cout<<"Enter the k for which you have to find out the missing number : ";
    cin>>k;
    cout<<"The kth missing number in the array is : "<<KthMissingNumber2(arr,k);
    return 0;
}