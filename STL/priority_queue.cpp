#include <bits/stdc++.h>
using namespace std;

void explainPq()
{
    priority_queue<int> pq; // max heap
    pq.push(15);            //{15}
    pq.push(10);            //{15,10}
    pq.push(20);            //{20,15,10}

    cout << pq.top() << endl; // 20

    pq.pop(); //{10,15}

    priority_queue<int, vector<int>,greater<int>> mnPq; // min heap
    mnPq.push(20); //{20}
    mnPq.push(15); // {15,20}
    mnPq.emplace(10); // {10,15,20}

    cout<<mnPq.top()<<endl; // 10

    mnPq.pop();
}

int main()
{
    cout << "--------";
    cout << endl
         << endl;
    explainPq();
    cout << endl
         << endl;
    cout << "--------";
}