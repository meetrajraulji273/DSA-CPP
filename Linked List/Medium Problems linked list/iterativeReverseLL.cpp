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

// brute - force method --> T.C ---> O(2n) ---> S.C ---> O(n)
Node* reverseLL1(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }

    temp = head;
    while(temp != nullptr){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }

    return head;
}

// optimal approach ---> T.C ---> O(n) ---> S.C ---> O(1)
Node* reverseLL2(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = head -> next;
    while(temp != nullptr){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main(){
    vector<int> arr = {12,76,8,4,7};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* head2 = reverseLL1(head);
    cout<<"After reversing the singly linked list : ";
    print(head2);

    Node* head3 = reverseLL2(head);
    cout<<"After reversing the singly linked list : ";
    print(head3);

    return 0;
}
