#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
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
    if(isSorted(arr,n)){
        cout<<"The array is sorted.";
    }else{
        cout<<"The array is not sorted.";
    }
}