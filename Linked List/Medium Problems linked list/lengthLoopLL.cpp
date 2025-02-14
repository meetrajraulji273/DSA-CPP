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
int lengthLoop1(Node* head){
    map<Node*,int> mpp;
    int timer = 1;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp -> next;
    }
    return 0;
}

// optimal approach ---> T.C ----> O(n) ---> S.C ---> O(1)
int findLength(Node* slow,Node* fast){
    fast = fast -> next;
    int cnt = 1;
    while(fast != slow){
        cnt++;
        fast = fast -> next;
    }
    return cnt;
}
int lengthLoop2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow){
            return findLength(slow,fast);
        }
    }
    return 0;
}

int main(){
    vector<int> arr= {3,1,4,6,2};
    Node *head = convertArr2LL(arr);
    print(head);

    int length = lengthLoop2(head);
    cout<<"The length of the loop in linked list : "<<length;

    return 0;
}