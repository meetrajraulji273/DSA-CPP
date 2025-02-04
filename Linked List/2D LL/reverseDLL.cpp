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

void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

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

//brute force method --> T.C --> O(2n) --> S.C ---> O(n)
Node* reverseDLL1(Node* head){
    stack<int> st;
    Node* temp = head;

    while(temp != nullptr){
        st.push(temp -> data);
        temp = temp -> next;
    }
    // here the temp would become nullptr 
    // so reintialise it again with head
    temp = head;
    while(temp != nullptr){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }

    return head;
}

//optimal approach --> T.C --> O(n) S.C ---> O(1)
Node* reverseDLL2(Node* head){
    Node* prev = nullptr;
    Node* temp = head;
    while(temp != nullptr){
        prev = temp -> back;
        temp -> back = temp -> next;
        temp -> next = prev;
        temp = temp -> back;
    }
    return prev->back;
}

int main(){
    vector<int> arr = {2,9,6,5,16,1};
    Node* head = convertArr2DLL(arr);
    print(head);

    Node* newHead = reverseDLL1(head);
    cout<<"After reversing the doubly linked list : ";
    print(newHead);

    Node* newHead2 = reverseDLL2(head);
    cout<<"After reversing the doubly linked list without using any space : ";
    print(newHead2);
    return 0;
}