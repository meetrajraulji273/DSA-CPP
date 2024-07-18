#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"--------";
    cout<<endl<<endl;

    pair<int, int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int ,pair<int,int>> o = {1,{3,4}};
    cout<<p.first<<" "<<o.second.first<<" "<<o.second.second<<endl;

    pair<int,int> arr[] = {{1,2},{3,4},{5,6},{7,8}};
    cout<<arr[1].second<<" "<<arr[3].first<<endl;

    cout<<endl<<endl;
    cout<<"--------";
}