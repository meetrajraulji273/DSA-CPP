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

// brute force method ---> T.C ---> O(n log n) ---> S.C ---> O(n);
Node* stNode1(Node* head){
    map<Node*,int> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return nullptr;
}

// optimal approach ---> T.C ---> O(n/2) ---> S.C ----> O(1)
Node* stNode2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main(){
    vector<int> arr = {1,2,3,6,7};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* stNode = stNode2(head);
    cout<<"Starting Node of the linked list is : "<<stNode -> data;
}