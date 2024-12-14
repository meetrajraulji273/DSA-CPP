#include<bits/stdc++.h>
using namespace std;

//Brute-Force method ---> T.C ---> O(n * n) ----> S.C ---> O(1)
void prodOfSubarray1(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int prod = 1;
        for(int j=i;j<n;j++){
            prod = prod * arr[j];
            maxi = max(maxi,prod);
        }
    }
    cout<<"Maximum product of any subarray is : "<<maxi;
}

//optimal-approach ---> T.C ---> O(n) ---> S.C ---> O(1)
void prodOfSubarray2(int arr[],int n){
    int maxi = INT_MIN;
    int prefix = 1;int suffix = 1;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix=1;
        if(suffix == 0) suffix=1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }
    cout<<"Maximum product of any subarray is : "<<maxi;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    prodOfSubarray2(arr,n);
    return 0;
}