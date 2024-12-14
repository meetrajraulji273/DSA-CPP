#include<bits/stdc++.h>
using namespace std;

int getSsmallest(int arr[],int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the elment arr["<<i<<"] : ";
        cin>>arr[i];
    }
    cout<<"The second smallest element in the array is : "<<getSsmallest(arr,n);
}