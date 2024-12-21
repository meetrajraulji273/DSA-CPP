#include<bits/stdc++.h>
using namespace std;

class Node{
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

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removesHead(Node* head){
    if(head == NULL || head->next==NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void print(Node* head){
    Node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
}

Node* removesTail(Node* head){
    if(head == NULL || head->next==NULL) return head;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

int main(){
    vector<int> arr = {7,10,18,22,28,45};
    Node* head = convertArr2LL(arr);
    cout<<"Old Head : "<<head->data<<endl;

    Node* newHead = removesHead(head);
    cout<<"New Head : "<<newHead->data<<endl;

    Node* newHead1 = removesTail(head);

    print(newHead);
    print(newHead1);

    return 0;
}