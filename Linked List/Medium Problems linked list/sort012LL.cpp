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

// brute force method --> T.C ---> O(2n) ---> S.C ---> O(1)
Node* sort012Brute(Node* head){
    if(head == nullptr || head -> next == nullptr) return head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node* temp = head;

    while(temp != nullptr){
        if(temp -> data == 0) cnt0++;
        else if(temp -> data == 1) cnt1++;
        else cnt2++;

        temp = temp -> next;
    }

    temp = head;
    while(temp != nullptr){
        if(cnt0){
            temp -> data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp -> data = 1;
            cnt1--;
        }else{
            temp -> data = 2;
            cnt2--;
        }
        temp = temp -> next;
    }

    return head;
}

// optimal approach --> T.C ---> O(n) ---> S.C --> O(1)
Node* sort012Optimal(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while(temp != nullptr){
        if(temp -> data == 0){
            zero -> next = temp;
            zero = temp;
        }else if(temp -> data == 1){
            one -> next = temp;
            one = temp;
        }else{
            two -> next = temp;
            two = temp;
        }
        temp = temp -> next;
    }
    
    zero -> next = (oneHead -> next) ? oneHead -> next : twoHead -> next;
    one -> next = twoHead -> next;
    two -> next = nullptr;

    delete oneHead;
    delete twoHead;

    return zeroHead -> next;
    delete zeroHead;
}

int main(){
    vector<int> arr = {2,1,0,0,0,2};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* head2 = sort012Brute(head);
    cout<<"After sorting the 0's ,1's and 2's in linked list : ";
    print(head);

    vector<int> arr1 = {0,1,1,0,1,2};
    Node* head3 = convertArr2LL(arr1);
    print(head3);

    Node* head4 = sort012Optimal(head3);
    cout<<"After sorting the o's ,1's and 2's in linked list : ";
    print(head4);
    
    return 0;
}