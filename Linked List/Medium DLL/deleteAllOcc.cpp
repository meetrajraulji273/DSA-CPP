#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public: 
    Node(int data1,Node* next1,Node*back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next= nullptr;
        back = nullptr;
    }
};

Node* convertArrTo2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return  head;
}

void print(Node* head){
    while(head != NULL){
        cout<< head -> data << " ";
        head = head -> next;
    }
    cout<<endl;
}

// brute force method ---> T.C ---> O(n) ---> S.C ---> O(n);
Node* delAllOcc(Node* head,int key){
    Node* temp = head;
    while(temp != nullptr){
        if(temp -> data == key){
            Node* nextNode = temp -> next;
            if(temp == head){
                head = head -> next;
            }
            Node* prev = temp -> back;
            Node* front = temp -> next;
            if(prev) prev -> next = front;
            if(front) front -> back = prev;

            free(temp);
            temp = nextNode;
        }else{
            temp = temp -> next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {10,8,10,1,10,11,10,14};
    Node* head = convertArrTo2DLL(arr);
    cout<<"After conversion of the array into doubly linked list : ";
    print(head);

    int key;
    cout<<"Enter the key of that you want to delete : ";
    cin>>key;
    Node* head2 = delAllOcc(head,key);
    print(head2);
    return 0;
}