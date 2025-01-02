#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
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

Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* insertTail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

Node* insertPosition(Node* head,int el,int k){
    if(head == nullptr){
        if(k==1){
            return new Node(el);
        }else{
            cout<<"Invalid Position ";
        }
    }
    if(k == 1){
        return new Node(el,head);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertBeforeValue(Node* head,int el,int x){
    if(head == nullptr){
       cout<<"Invalid Position";
    }
    if(head->data == x){
        return new Node(el,head);
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data == x){
            Node* newNode = new Node(el,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {7, 10, 18, 22, 28, 45};
    Node *head = convertArr2LL(arr);
    cout<<"Old Head : "<<head->data<<endl;
    print(head);

    Node* newHead = insertHead(head,11);
    cout<<"After inserting the value 11 : ";
    print(newHead);
    Node* newHead1 = insertTail(newHead,15);
    cout<<"After inserting the value 15 : ";
    print(newHead1);

    Node* newHead2 = insertPosition(newHead1,19,4);
    cout<<"After inserting value 19 at 4th position : ";
    print(newHead2);

    Node* newHead3 = insertBeforeValue(newHead2,20,28);
    cout<<"After inserting value 20 before 28 value node : ";
    print(newHead3);
}