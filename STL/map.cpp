#include <bits/stdc++.h>
using namespace std;

void explainMap()
{
    map<int, int> mp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mppp;
    mp[1] = 2;         //[{1,2}]
    mp.insert({2, 4}); // [{1,2},{2,3}]
    mp.insert({3, 1}); //[{1,2},{2,4},{3,1}]

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    auto it = mp.find(3);
    if (it != mp.end())
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << mp[1] << endl;
    cout << mp[5] << endl;
}

void explainMultimap()
{
    multimap<int, int> mp;

    // same as map but it will have multiple values stiored for the same key
}

void explinUnorderedMap(){
    unordered_map<int,int> mp;

    //same as map but store the value in unordered format but will have unique keys.
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    explainMap();

    cout << endl
         << endl;
    cout << "--------";
}