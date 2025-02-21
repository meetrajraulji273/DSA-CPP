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

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// brute force method ---> T.C ----> O(n + n/2) ---> S.C ----> O(1);
Node* delMidNode1(Node* head){
    if(head == nullptr || head -> next == nullptr){
        return nullptr;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        temp = temp -> next;
    }
    temp = head;
    int midN = cnt / 2;
    while(temp != nullptr){
        midN--;
        if(midN == 0){
            Node* midNode = temp -> next;
            temp -> next = temp -> next -> next;
            delete(midNode);
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// optimal approach ---> T.C ----> O(n/2) ----> S.C ---> O(1)
Node* delMidNode2(Node* head){
    if(head == nullptr || head -> next == nullptr){
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    fast = fast -> next -> next ;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* midNode = slow -> next;
    slow -> next = slow -> next -> next;
    delete(midNode);
    return head;
}

int main(){
    vector<int> arr = {1,2,3,6,7};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* head2 = delMidNode2(head);
    print(head2);
}