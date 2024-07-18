#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first>p2.first) return true;
    return false;
}

void explainSort()
{
    pair<int,int> a[] = {{2,1},{4,1},{2,4}};
    sort(a,a+3,comp);

    for(auto it : a){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main()
{
    cout << "--------";
    cout << endl;
    cout << endl;

    explainSort();

    cout << endl;
    cout << endl;
    cout << "--------";
}