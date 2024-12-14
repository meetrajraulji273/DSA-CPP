#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n){
    int reverse_no = 0;
    while(n){
        int last_digit = n%10; 
        reverse_no = reverse_no*10 + last_digit;
        n = n/10;
    }
    cout<<reverse_no<<endl;
    if(n > INT_MAX || n < INT_MIN) return 0; 
    return reverse_no;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int n;
    cout<<"Enter the number of times you have to run the Program : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter the number : ";
        cin>>num;
        cout<<"Reversed Number is : "<<reverseNumber(num)<<endl;
    }
    
    cout<<endl<<endl;
    cout<<"--------";
}