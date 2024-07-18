#include <bits/stdc++.h>
using namespace std;

void explainList()
{
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(4);

    for (auto it : ls)
    {
        cout << it << " ";
    }

    cout << endl;
    ls.push_front(2);
    ls.emplace_front(3); // {3,2,1,4}
    for (auto it : ls)
    {
        cout << it << " ";
    }
    // rest of the functions same as vector
    //  begin, end , rbegin , rend, clear, insert, size,swap
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    explainList();

    cout << endl
         << endl;
    cout << "--------";
}