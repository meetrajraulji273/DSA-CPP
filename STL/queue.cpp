#include<bits/stdc++.h>
using namespace std;

void explainQueue(){
    cout<<"Queue is a linear data structure, in which the operations are performed in FIFO order(First In First Out). The queue is an example of sequential collection data structures (Linear Data Structure). The queue is open at one end. It is similar to a real-life queue where people wait for their turn to get something done."<<endl<<endl;

    queue<int> q;
    q.push(25);
    q.push(40);
    q.emplace(35);

    q.back() += 9;

    cout<<q.back()<<endl;
    
    cout<<q.front()<<endl;
    
    q.pop();

    cout<<q.front()<<endl;
}

int main(){
    cout<<"--------";
    cout<<endl<<endl;
    
    explainQueue();

    cout<<endl<<endl;
    cout<<"--------";
}