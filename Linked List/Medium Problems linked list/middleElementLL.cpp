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

Node* middleElement1(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    temp = head;
    int midN = (cnt/2) + 1;
    while(temp != nullptr){
        midN--;
        if(midN == 0){
            break;
        }
        temp = temp -> next;
    }
    return temp;
}

Node* middleElement2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != nullptr && fast != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main(){
    vector<int> arr= {3,1,4,6,2};
    Node *head = convertArr2LL(arr);
    print(head);

    Node* midNode1 = middleElement1(head);
    cout<<midNode1 -> data <<endl;

    Node* midNode2 = middleElement2(head);
    cout<<midNode2 -> data <<endl;

    return 0;
}