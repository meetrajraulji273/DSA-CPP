#include <bits/stdc++.h>
using namespace std;

void explainSet()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.emplace(15);
    s.emplace(15);
    s.insert(76);
    s.insert(46);

    auto it1 = s.find(10);
    auto it2 = s.find(15);

    s.erase(20);

    for (auto it : s)
    {
        cout << it << " ";
    }

    cout << endl;

    s.erase(it1, it2);
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout<<endl;
    cout<<s.count(20)<<endl; // 0
    cout<<s.count(15)<<endl; // 1
    
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;
    explainSet();
    cout << endl
         << endl;
    cout << "--------";
}