#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

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
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

bool checkIfPresent(Node* head,int x){
    Node* temp = head;
    while(temp){
        if(temp->data==x) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {999,87,54,34,7,90,56};
    Node* head = convertArr2LL(arr);
    cout<<head->data<<endl;

    int length = lengthOfLL(head);
    cout<<"Length of the linked list is : "<<length<<endl;
    
    int x;
    cout<<"Enter the number that you have to find in LL : ";
    cin>>x;
    if(checkIfPresent(head,x)){
        cout<<"Number is present";
    }else{
        cout<<"Number is not present";
    }

    return 0;
}