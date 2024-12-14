#include<bits/stdc++.h>
using namespace std;

//brute force method ---> T.C ----> o(NlogN)
// int getLargest(int arr[],int n){
//     quick_sort(arr,0,n-1);
//     int largest = arr[n-1];
//     return largest;
// }

//optimal approach ---> T.C ----> o(N)
int getLargest1(int arr[],int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
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
    
    //brute force method
    // cout<<"The largest element in the array is : "<<getLargest(arr,n);
    //optimal approach
    cout<<"The largest element in the array is : "<<getLargest1(arr,n);
}