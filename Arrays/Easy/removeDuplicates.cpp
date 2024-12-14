#include<bits/stdc++.h>
using namespace std;

//brute force method
void removeDuplicates1(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int index = 0;
    for(auto it: s){
        arr[index] = it;
        index++;
    }
    for(int i=index;i<n;i++){
        arr[i] = 0;
    }
    cout << "Size of array after removing duplicates: " << index << endl;
}

//optimale approach
void removeDuplicates2(int arr[],int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout << "Size of array after removing duplicates: " << i+1 << endl;
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
    removeDuplicates2(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
    }
}