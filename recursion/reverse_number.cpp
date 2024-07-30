#include<bits/stdc++.h>
using namespace std;

void f(int n){
    if(n<1)
    return ;
    cout<<n<<" ";
    f(n-1);
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    f(n);
}
