#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
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

Node *removesHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
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

Node *removesTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node *removesk(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        free(temp);
        head = head->next;
        return head;
    }
    Node *temp = head;
    int cnt = 0;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
            prev = temp;
            temp = temp->next;
    }
    return head;
}

Node* removesEl(Node* head,int el){
    if(head == nullptr) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main()
{
    vector<int> arr = {7, 10, 18, 22, 28, 45};
    Node *head = convertArr2LL(arr);
    cout<<"Old Head : "<<head->data<<endl;
    print(head);

    Node* newHead = removesHead(head);
    cout<<"New Head : "<<newHead->data<<endl;
    print(newHead);

    Node* newHead1 = removesTail(newHead);
    cout<<"After removing the tail : ";
    print(newHead1);

    Node* newHead2 = removesk(newHead1, 3);
    cout<<"After removing the third element : ";
    print(newHead2);

    Node* newHead3 = removesEl(newHead2,18);
    cout<<"After removing the element 18 : ";
    print(newHead3);


    return 0;
}