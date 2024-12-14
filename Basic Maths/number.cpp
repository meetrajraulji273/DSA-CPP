#include<bits/stdc++.h>
using namespace std;

int countNumber(int n){
    int count = 0;
    while(n>0){
        count = count+1;
        n=n/10;
    }
    return count;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int n;
    cout<<"Enter the number of times you have to run the Program : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter the number:";
        cin>>num;
        cout<<"Number of digits in the number is :"<<countNumber(num)<<endl;
    }

    
    cout<<endl<<endl;
    cout<<"--------";
}