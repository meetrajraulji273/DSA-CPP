#include <bits/stdc++.h>
using namespace std;

void explainMultiSet()
{
    multiset<int> m;
    m.insert(1);
    m.insert(1);
    m.insert(1); // {1,1,1}

    cout << m.count(1) << endl; // 3

    m.erase(1); // { }

    m.insert(2);
    m.insert(2);
    m.insert(2); // {2,2,2}

    m.erase(m.find(2)); //{2,2}

    cout << m.count(2) << endl;
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    explainMultiSet();

    cout << endl
         << endl;
    cout << "--------";
}