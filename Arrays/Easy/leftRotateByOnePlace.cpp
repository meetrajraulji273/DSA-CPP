#include<bits/stdc++.h>
using namespace std;

//brute-force-method --> T.C ---> 0(n)
void leftRotate(int arr[],int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main(){
    int n;
    cout<<"Enter the strength of the array : ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    leftRotate(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}