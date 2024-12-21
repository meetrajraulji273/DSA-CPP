#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr; 
    }
};

int main(){
    vector<int> arr = {5,12,6,17,19};
    Node y = Node(arr[0]);
    cout<<y.data<<endl;
    cout<<y.next<<endl;
    
    Node x = Node(arr[1]);
    Node *z = new Node(x.data,&x);
    cout<<z->data<<endl;
    cout<<z->next<<endl;

};