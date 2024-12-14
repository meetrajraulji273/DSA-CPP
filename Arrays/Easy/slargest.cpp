#include<bits/stdc++.h>
using namespace std;

//brute force approach ---> T.C ----> o(NlogN + N)
int getSlargest1(int arr[],int n){
    int slargest = -1;
    // quick_sort(arr,0,n-1);
    int largest = arr[n-1];
    for(int i=n-2;i>=0;i++){
        if(arr[i]!=largest){
            slargest = arr[i];
        }
    }
    return slargest;
}

//better approach ---> T.C ----> o(N + N)
int getSlargest2(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for(int i=n-2;i>=0;i++){
        if(arr[i]!=largest){
            slargest = arr[i];
        }
    }
    return slargest;
}

//optimal approach ---> T.C ----> o(N)
int getSlargest3(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    int n;
    cout<<"enter the strength of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }

    //brute force approach ---> T.C ----> o(NlogN + N)
    // cout<<"The second largest element in the array : "<<getSlargest1(arr,n);

    //better approach ---> T.C ----> o(N + N)
    cout<<"The second largest element in the array : "<<getSlargest2(arr,n);

    //optimal approach ---> T.C ----> o(N)
    cout<<"The second largest element in the array : "<<getSlargest3(arr,n);

}