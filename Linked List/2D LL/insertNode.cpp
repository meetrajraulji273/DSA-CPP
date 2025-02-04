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

Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head -> back = newHead;
    return newHead;
}

void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

Node* insertBeforeTail(Node* head,int val){
    if (head == nullptr) return nullptr;
    if(head -> next == nullptr){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* temp = new Node(val,tail,prev);
    prev -> next = temp;
    tail -> back = temp;

    return head;
}

Node* insertBeforeKthElement(Node* head,int k,int val){
    if(head == nullptr){
        return new Node(val);
    }
    if(k=1){
        return insertBeforeHead(head,val);
    }
    Node* temp = head;
    int cnt  = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(val,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

void insertBeforeNode(Node* temp,int val3){
    Node* prev = temp -> back;
    Node* newNode = new Node(val3,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;
}

int main(){
    vector<int> arr = {2,9,6,5,16,1};
    Node* head = convertArr2DLL(arr);
    print(head);

    //insert before end
    cout<<"--------------";
    cout<<endl;
    cout<<"insert before end";
    cout<<endl;
    int val;
    cout<<"Enter the value to insert : ";
    cin>>val;
    Node* newHead = insertBeforeHead(head,val);
    cout<<"After inserting the "<<val<<"Node before the linked list : ";
    print(newHead);
    
    // insert before tail

    cout<<endl;
    cout<<"--------------";
    cout<<endl;
    cout<<"insert before tail"<<endl;
    
    int val1;
    cout<<"Enter the value to be inserted before tail of the linked list : ";
    cin>>val;
    Node* newHead1 = insertBeforeTail(head,val);
    cout<<"After inserting the "<<val<<"Node before the tail of the linked list : ";
    print(newHead1);

    // insert before kth element
    cout<<endl;
    cout<<"--------------";
    cout<<endl;
    cout<<"insert before kth element";

    int k;
    int val2;
    cout<<"Enter the position that you want the element to be inserted : ";
    cin>>k;
    cout<<"Enter the value of the element : ";
    cin>>val2;

    Node* newHead2 = insertBeforeKthElement(head,k,val);
    cout<<"After inserting the node before kth element : ";
    print(newHead2);

    //insert before the given node
    cout<<endl;
    cout<<"--------------";
    cout<<endl;
    
    
    int val3;
    cout<<"Enter the value of the element : ";
    cin>>val3;
    insertBeforeNode(newHead2 -> next,val3);
    cout<<"After inserting the node before given node : ";
    print(newHead2);
    
   return 0;
} 