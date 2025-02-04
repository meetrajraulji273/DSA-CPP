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

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

// brute force method --> T.C ---> O(len) + O(len-n) ---> S.C --> O(1) 
Node* rmNthEndNodeLL1(Node* head,int n){
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp -> next;
    }

    temp = head;
    int res = cnt - n;
    if(res == 0){
        return head -> next;
    }
    while(temp != nullptr){
        res--;
        if(res == 0){
            break;
        }
        temp = temp -> next;
    }

    Node* delNode = temp -> next;
    temp -> next = temp -> next -> next;

    delete delNode;

    return head; 
}

// optimal approach --> T.C -- O(n) --> S.C ---> O(1);
Node* rmNthEndNodeLL2(Node* head,int n){
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++){
        fast = fast -> next;
    }

    if(fast == nullptr){
        return head -> next;
    }

    while(fast -> next != nullptr){
        fast = fast -> next;
        slow = slow -> next;
    }
    
    Node* delNode = slow -> next;
    slow -> next = slow -> next -> next;

    delete delNode;

    return head; 

}

int main(){
    vector<int> arr = {2,1,0,0,0,2};
    Node* head = convertArr2LL(arr);
    print(head);

    int n;
    cout<<"Enter the Node that you want to delete from the end : ";
    cin>>n;
    Node* head2 = rmNthEndNodeLL1(head,n);
    cout<<"After deleting the Nth node from end : ";
    print(head2);

    vector<int> arr1 = {2,1,0,0,0,2};
    Node* head3 = convertArr2LL(arr1);
    print(head3);

    int n1;
    cout<<"Enter the Node that you want to delete from the end : ";
    cin>>n1;
    Node* head4 = rmNthEndNodeLL2(head3,n1);
    cout<<"After deleting the Nth node from end : ";
    print(head4);
    
    return 0;
}