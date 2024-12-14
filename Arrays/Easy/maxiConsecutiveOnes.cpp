#include<bits/stdc++.h>
using namespace std;

//optimal approach ---> T.C ---> o(n) ---> S.C ---> o(1);
int getMaxiConsecutiveOne(int arr[],int n){
    int maxi = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi = max(maxi,count);
        }else{
            count = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the strength of the binary array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    int max = getMaxiConsecutiveOne(arr,n);
    cout<<"Maximun consecutive Ones are : "<<max;
    return 0;
}