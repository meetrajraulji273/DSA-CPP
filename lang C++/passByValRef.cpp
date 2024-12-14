#include<bits/stdc++.h>
using namespace std;

//pass by value
void passByValue(int num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num +=5;
    cout<<num<<endl;
}
//pass by reference
void passByRef(int &num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num +=5;
    cout<<num<<endl;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    int num =10;

    passByValue(num);
    cout<<num<<endl;

    cout<<"--------";
    cout<<endl<<endl;

    passByRef(num);
    cout<<num<<endl;
    
    cout<<endl<<endl;
    cout<<"--------";
    return 0;
}