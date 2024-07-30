#include <bits/stdc++.h>
using namespace std;

void f(int i,int n){
    if(i>n)
    return;
    cout<<"Meetraj"<<endl;
    f(i+1,n);
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    int n;
    cout<<"Enter the Number of times you have to print your name : "<<endl;
    cin>>n;
    f(1,n);
    
    cout << endl
         << endl;
    cout << "--------";
}