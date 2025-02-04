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
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverseLL(Node* head){
    if(head == nullptr || head -> next == nullptr){
        return head;
    }

    Node* newHead = reverseLL(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;
    return newHead;
}

int main(){
    vector<int> arr = {12,76,8,4,7};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* head2 = reverseLL(head);
    cout<<"After reversing the doubly linked list : ";
    print(head2);

    return 0;
}