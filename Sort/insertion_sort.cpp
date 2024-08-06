#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(arr[j-1]>arr[j] && j>0){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
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
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}