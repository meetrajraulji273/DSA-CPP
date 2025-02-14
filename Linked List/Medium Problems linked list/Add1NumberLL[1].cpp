#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

Node* convertArr2LL(vector<int> &arr1){
    Node* head = new Node(arr1[0]);
    Node* prev = head;
    for(int i=1;i<arr1.size();i++){
        Node* temp = new Node(arr1[i]);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* reverseLL(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* newHead = reverseLL(head->next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;

    return newHead;
}

// brute-force method --> T.C ---> O(3n) ---> S.C ---> O(1);
Node* Add1NumberLL1(Node* head){
    Node* newHead = reverseLL(head);
    Node* temp = newHead;
    int carry = 1;
    while(temp != nullptr){
        temp -> data = temp -> data + carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            temp -> data = temp -> data % 10;
            carry = 1;
        }
        temp = temp -> next;
    }

    if(carry == 1){
        Node* newNode = new Node(1);
        Node* newHead2 = reverseLL(newHead);
        newNode -> next = newHead2;
        return newNode;
    }

    Node* newHead2 = reverseLL(newHead);

    return newHead2;
}

int helper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = helper(temp -> next);
    temp -> data = temp -> data + carry;
    if(temp -> data < 10){
        return 0;
    }
    temp -> data = temp -> data % 10;
    return 1;
}

// optimal approach ---> T.C ---> O(n) ---> Stack Space --> O(n)
Node* Add1NumberLL2(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode -> next = head;
        return newNode;
    }
    return head;
}

int main(){
    cout<<"Raulji Kuldeepsinh Sanjaysinh."<<endl;
    vector<int> arr1;
    arr1.push_back(9);
    arr1.push_back(9);
    arr1.push_back(9);
    arr1.push_back(9);
    Node* head = convertArr2LL(arr1);
    cout<<"Given Linked list is : ";
    print(head);

    Node* head1 = Add1NumberLL2(head);
    cout<<"After adding 1 to the given linked list : ";
    print(head1);
    return 0;
}