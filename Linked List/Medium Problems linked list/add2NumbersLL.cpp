#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

Node* add2Numbers(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry = 0;
    while(t1 != nullptr || t2 != nullptr){
        int sum = carry;
        if(t1) sum = sum + t1 -> data;
        if(t2) sum = sum + t2 -> data;

        Node* newNode = new Node(sum%10);
        carry = sum / 10;

        current -> next = newNode;
        current = newNode;

        if(t1) t1 = t1 -> next;
        if(t2) t2 = t2 -> next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        current -> next = newNode;
    }

    return dummyNode -> next;
}

int main(){
    vector<int> arr1 = {2,9,6,5,7,1};
    Node* head1 = convertArr2DLL(arr1);
    print(head1);

    vector<int> arr2 = {8,7,5,10,7,5};
    Node* head2 = convertArr2DLL(arr2);
    print(head2);

    Node* head3 = add2Numbers(head1,head2);
    cout<<"After addition of 2 linked list : ";
    print(head3);

    return 0;
} 