#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }

    //pre compute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    //map has a unique key and sorted asc
    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cout<<"Enter the number of queries : ";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the Number : ";
        cin>>num;
        cout<<"Entered number occurs : "<<mpp[num]<<endl;
    }
}