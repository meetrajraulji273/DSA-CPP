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

Node* yNode;

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
        if(temp -> data == 4){
            yNode = temp;
        }
        if(temp -> data == 5){
            temp -> next = yNode;
        }
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

Node* findIntersectionLL1(Node* head1,Node* head2){
    map<Node*,int> mpp;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != nullptr){
        mpp[t1] = 1;
        t1 = t1 -> next;
    }
    
    while(t2 != nullptr){
        if(mpp.find(t2) != mpp.end()){
            return t2;
        }
        t2 = t2 -> next;
    }

    return nullptr;
}

Node* findIntersectionLL2(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int n1 = 0;
    int n2 = 0;
}

int main(){
    vector<int> arr1 = {3,1,4,6,2};
    Node *head1 = convertArr2LL(arr1);
    print(head1);
    vector<int> arr2 = {1,2,4,5,4,6,2};
    Node* head2 = convertArr2LL(arr2);
    print(head2);

    Node* YNode = findIntersectionLL2(head1,head2);
    cout<<YNode -> data;

    return 0;
}