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

// brute force method ---> T.C ---> O(n * 2 log n) ---> S.C ---> O(1)
bool detectLoop1(Node* head){
    Node* temp = head;
    map<Node*,int> mpp;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return false;
}

bool detectLoop2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr= {3,1,4,6,2};
    Node *head = convertArr2LL(arr);
    print(head);

    if(detectLoop2(head)){
        cout<<"There is a loop in the linked list";
    }else{
        cout<<"There is no loop in the linked list";
    }

    return 0;
}