//Addition,max and min two numbers by using of user-defined functions and in-built functions of math.h library
#include<bits/stdc++.h>
using namespace std;

int sum(int num1,int num2){
    return num1+num2;
}

int maximum(int num1,int num2){
    if(num1>=num2) return num1;
    else return num2;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int num1,num2;
    cout<<"Enter the two numbers :"<<endl;
    cin>>num1>>num2;
    
    int res = sum(num1,num2);
    cout<<"Addition of the two numbers are : "<<res<<endl;

    int max = maximum(num1,num2);
    cout<<"Maximum of the two numbers is : "<<max<<endl;

    int minimum = min(num1,num2);
    cout<<"Minimum of the two numbers is : "<<minimum<<endl;

    cout<<endl<<endl;
    cout<<"--------";
    return 0;
}