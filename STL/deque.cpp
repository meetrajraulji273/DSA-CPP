#include <bits/stdc++.h>
using namespace std;

void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);     //{1}
    dq.emplace_back(2);  //{1,2}
    dq.push_front(7);    //{7,1,2}
    dq.emplace_front(3); //{3,7,1,2}

    dq.pop_back();  //{3,7,1}
    dq.pop_front(); //{7,1}

    dq.back(); //{1}
    dq.front(); //{7}

    cout<<dq.empty()<<endl; //0 => fasle

    for (auto it : dq)
    {
        cout << it << " ";
    }
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;

    explainDeque();

    cout << endl
         << endl;
    cout << "--------";
}