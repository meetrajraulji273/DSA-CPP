#include<bits/stdc++.h>
using namespace std;

//brute force method --> T.C ---> 0(n+d) 
// void leftRotate(int arr[],int n,int d){
//     d=d%n;
//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i] = arr[i];
//     }
//     for(int i=d;i<n;i++){
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d;i<n;i++){
//         arr[i] = temp[i-(n-d)];
//     }
// }

//optimal approach --> T.C ---> 0(2n)
void leftRotate(int arr[],int n,int d){
    d=d%n;
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
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
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int d;
    cout<<"Enter the places by which you want to left rotate the array : ";
    cin>>d;
    leftRotate(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}