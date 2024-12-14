#include<bits/stdc++.h>
using namespace std;

int euclideanAlgo(int a,int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    else return a;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

   int a,b;
   cout<<"Enter the Number a and b : ";
   cin>>a>>b;
   cout<<"The HCF is : "<<euclideanAlgo(a,b);
    
    cout<<endl<<endl;
    cout<<"--------";
}