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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head -> next;
    head -> back = nullptr;
    prev -> next = nullptr;
    free(prev);

    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head -> next == nullptr){
        return nullptr;
    }

    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    tail -> back = nullptr;
    prev -> next = nullptr;
    free(tail);

    return head;
     
}

Node* deleteK(Node* head,int k){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp -> next;
    }
    if (temp == nullptr) {
    cout << "The position exceeds the length of the linked list." << endl;
    return head;
    }
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if(prev == nullptr || front == nullptr){
        return nullptr;
    }else if(prev ==  nullptr){
        return deleteHead(head);
    }else if(front == nullptr){
        return deleteTail(head);
    }
        prev -> next = front;
        front -> back = prev;

        temp -> next = nullptr;
        temp -> back = nullptr;

        delete temp;
   
        return head;
}

void deleteNode(Node* temp){
    Node* prev = temp -> back;
    Node* front = temp -> next;
    
    if(front == nullptr){
        prev -> next = nullptr;
        temp -> back = nullptr;
        free(temp);
        return;
    }
    prev -> back = front;
    front-> back = prev;

    temp -> back = temp -> next = nullptr;
    free(temp);
}


int main(){
    vector<int> arr = {5,8,9,1,6,11,10,14};
    Node* head = convertArrTo2DLL(arr);
    cout<<"After conversion of the array into doubly linked list : ";
    print(head);

    Node* newHead = deleteHead(head);
    cout<<"After deleting the head of the doubly linked list : ";
    print(newHead);

    Node* newHead2 = deleteTail(newHead);
    cout<<"After deleting the tail of the doubly linked list : ";
    print(newHead2);

    int k;
    cout<<"Enter the element that you want to delete linked list : ";
    cin>>k;
    Node* newHead3 = deleteK(newHead2,k);
    cout<<"After deleting the "<<k<<"th element of linked list : ";
    print(newHead3);

    // vector<int> arr1 = {5,8,9,1,6,11,10,14};
    // Node* head1 = convertArrTo2DLL(arr1);

    // deleteNode(newHead3->next->next->next);
    // cout<<"After deleting the node given other then head of the linked list :";
    // print(newHead3);

    if (newHead3 != nullptr && newHead3->next != nullptr && newHead3->next->next != nullptr) {
        deleteNode(newHead3->next->next);
        cout << "After deleting a node other than the head of the linked list: ";
        print(newHead3);
    } else {
        cout << "The list does not have enough nodes to perform deleteNode." << endl;
    }
    
    return 0;      
}

