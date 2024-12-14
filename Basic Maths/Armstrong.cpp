#include<bits/stdc++.h>
using namespace std;

bool explainArmstrong(int n){
    int sum = 0;
    int temp = n;
    while(n>0){
        int last_digit = n % 10;
        sum = sum + last_digit*last_digit*last_digit;
        n = n/10;
    }
    if(temp == sum) return true;
    else return false; 
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int n;
    cout<<"Enter the Number : ";
    cin>>n;

    if(explainArmstrong(n)){
        cout<<"Armstrong Number";
    }else{
        cout<<"Not an Armstrong";
    };
    
    cout<<endl<<endl;
    cout<<"--------";
}