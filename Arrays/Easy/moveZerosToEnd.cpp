#include<bits/stdc++.h>
using namespace std;

//brute-force method --> T.C ---> 0(n+n)
void moveZeroToEnd(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i] = temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i] = 0;
    }

}

//optimal approach --> T.C ---> 0(n) --> o(n)
// void moveZeroToEnd(int arr[],int n){
//     int j=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             j=i;
//             break;
//         }
//     }
//     if(j==-1) return;
//     for(int i=j+1;i<n;i++){
//         if(arr[i]!=0){
//             swap(arr[i],arr[j]);
//             j++;
//         }
//     }
// }

int main(){
    int n;
    cout<<"Enter the strenght of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }
    moveZeroToEnd(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}