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

Node* convertArr2LL(vector<int> &arr)
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
void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

// brute force method ---> T.C ---> O(3n) --> S.C ---> O(n);
Node* oddEvenLL1(Node* head){
    Node* temp = head;
    vector<int> arr;
    while(temp != nullptr && temp -> next != nullptr){
        arr.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp){
        arr.push_back(temp -> data);
    }
    temp = head -> next;
    while(temp != nullptr && temp -> next != nullptr){
        arr.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp){
        arr.push_back(temp -> data);
    }
    
    int i = 0 ;
    temp = head;
    while(temp != nullptr){
        temp -> data = arr[i];
        i++;
        temp = temp -> next;
    }

    return head;
}

//optimal-approach ---> T.c ---> O(n) ---> S.C ---> O(1);
Node* oddEvenLL2(Node* head){
    Node* odd = head;
    Node* even = head -> next;
    Node* evenHead = head -> next;
    while(even != nullptr && even -> next != nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd -> next;
        even = even -> next;
    }

    odd->next = evenHead;

    return head;
}

int main(){
    vector<int> arr = {2,9,6,5,7,1};
    Node* head = convertArr2LL(arr);
    print(head);

    Node* head2 = oddEvenLL1(head);
    cout<<"Odd and even linked list is as follows : ";
    print(head2);

    Node* head3 = oddEvenLL2(head);
    cout<<"Odd and even linked list is as follows : ";
    print(head3);

    return 0;
}
