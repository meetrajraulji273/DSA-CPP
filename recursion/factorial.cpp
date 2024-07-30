#include<bits/stdc++.h>
using namespace std;

void f(int n,int fact){
    if(n<1){
        cout<<fact;
        return ;
    }
    f(n-1,fact*n);
}

int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1); 
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<fact(n);
    // f(n,1);
}
