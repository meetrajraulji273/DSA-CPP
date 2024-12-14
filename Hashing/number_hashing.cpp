#include<bits/stdc++.h>
using namespace std;

int hashh[10000000];

int main(){
    //taking the array's length and elements
    int n;
    cout<<"Enter the strength of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element arr["<<i<<"] : ";
        cin>>arr[i];
    }

    //pre storing && pre computation
    //strength of the hash array is being limited inside the int main function which is around 1e6
    hashh[10000000] = {0};
    for(int i=0;i<n;i++){
        hashh[arr[i]] += 1;
    }

    //taking the no. of query and the query numbers and fetching from the hash array
    int q;
    cout<<"Enter the no. of queries : ";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the number to search : ";
        cin>>num;
        cout<<hashh[num]<<endl;
    }
}