#include<bits/stdc++.h>
using namespace std;

void f(int n){
    if(n<1)
    return ;
    f(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter the Number : ";
    cin>>n;
    f(n);
}