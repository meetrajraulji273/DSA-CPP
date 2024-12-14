#include<bits/stdc++.h>
using namespace std;

// ----> variety 1: given row and column find out the respective element at that particular row and column
// T.C ---> O(no. of column) ----> O(r) ----> S.C ----> O(1)
int nCr(int n,int r){
    int el = 1;
    for(int i=0;i<r;i++){
        el = el * (n-i);
        el = el/(i+1);
    }
    return el;
}
int variety1(){
    int r,c;
    cout<<"Enter the number of row and column you want to find the element : ";
    cin>>r>>c;
    cout<<"The element that row and column is : "<<nCr(r-1,c-1);
    return 0;
}

// variety 2 : given no. of row and we have to print that row of the pascal triangle
// Brute-force method ---> T.C ----> O(N * r) ----> o(1)
void printRow1(int row){
    for(int i=1;i<=row;i++){
        cout<<nCr(row-1,i-1)<<" ";
    }
}
// optimal-approach ---> T.C ---> O(N) ---> S.C ---> O(1)
void printRow2(int row){
    cout<<"1"<<" ";
    long long ans = 1;
    for(int i=1;i<row;i++){
        ans = ans * (row - i);
        ans = ans / i;
        cout<<ans<<" ";
    }
}

int variety2(){
    int row;
    cout<<"Enter the row which you want to print : ";
    cin>>row;

    printRow2(row);
    return 0;
}

// variety3 : given the the no. of rows , we have to print the pascal triangle till that row
// brute - force method ---> T.C O(n * n * n) ----> S.C ---> O(1)
void printTriangle(int row){
    for(int i=1;i<row;i++){
        for(int j=1;j<i;i++){
            cout<<nCr(i,j)<<" ";
        }
    }
}
void variety3(){
    int row;
    cout<<"Enter the row till you want to print the pascal triangle : ";
    cin>>row;

    printTriangle(row);
}

int main(){
    variety3();
    return 0;
}