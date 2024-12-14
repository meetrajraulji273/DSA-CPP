#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "--------";
    cout << endl;
    cout << endl;

    vector<int> v(5, 20);
    v.push_back(7);
    v.emplace_back(19);
    vector<int>::iterator it = v.begin();
    // it++;
    // cout<<*(it)<<" ";

    // it = it + 3;
    // cout<<*(it)<<" ";

    // vector<int>::iterator it = v.end();

    // vector<int>::iterator it = v.rend();

    // vector<int>::iterator it = v.rbegin();

    // for(vector<int>::iterator it =v.begin();it!=v.end();it++){
    //     cout<<*(it)<<" ";
    // }

    // for(auto it=v.begin();it!=v.end();it++){
    //     cout<<*(it)<<" ";
    // }

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    // {20,20,20,20,20,7,19} => {20,20,20,20,7,19}
    v.erase(v.begin() + 1);

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    // { 20, 20, 20, 20, 7, 19 } => {20,20,20,19}
    v.erase(v.begin() + 3, v.begin() + 5); //[start,end)

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    // {20,20,20,19} => {5,20,20,20,19}
    v.insert(v.begin(), 5);
    for (auto it : v)
    {
        cout << it << " ";
    }
    //{5,20,20,20,19} => {5,20,20,20,19,14}
    cout << endl;
    v.insert(v.end(), 14);
    for (auto it : v)
    {
        cout << it << " ";
    }
    // {5,20,20,20,19,14} => {5,20,20,27,27,20,19,14}
    cout << endl;
    v.insert(v.begin() + 3, 2, 27);
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    //{5,20,20,27,27,20,19,14} => {5,20,9,9,20,27,27,20,19,14}
    vector<int> copy(2, 9);
    v.insert(v.begin() + 2, copy.begin(), copy.end());
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
    cout << v.size(); // 10

    cout << endl;
    // cout << v.pop_back(); // {5}
    // cout << v.clear();  clear the vector

    // v => {9,9} copy => {5,20,9,9,20,27,27,20,19,14}
    v.swap(copy);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : copy)
    {
        cout << it << " ";
    }

    cout << endl;
    vector<int> m;
    cout << m.empty(); // 1
    cout << endl;
    cout << v.empty(); // 0

    cout << endl;
    cout << endl;
    cout << "--------";
}