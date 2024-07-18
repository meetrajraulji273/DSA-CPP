#include<bits/stdc++.h>
using namespace std;

void doSomething(int arr[]){
    arr[0] += 100;
    cout<<"value inside do something : "<<arr[0]<<endl;
}
int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int arr[5];

    for(int i=0;i<=4;i++){
        cout<<"enter the value for arr["<<i<<"] : ";
        cin>>arr[i];
    }
    doSomething(arr);
    cout<<"value inside int main : "<<arr[0]<<endl;
    
    cout<<endl<<endl;
    cout<<"--------";
    return 0;
}