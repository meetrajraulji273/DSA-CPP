#include<bits/stdc++.h>
using namespace std;

bool explainPalindrome(int n){
    int r = 0;
    int num = n;
    while(n>0){
    r = r*10 + n%10;
    n = n/10;
    }
    if(r == num) return true;
    else return false;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int n;
    cout<<"Enter the number : ";
    cin>>n;
    if(explainPalindrome(n)){
        cout<<"The number is palindrome";
    }else{
        cout<<"The number is not palindrome";
    }
    
    cout<<endl<<endl;
    cout<<"--------";
}