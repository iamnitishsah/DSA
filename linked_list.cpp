#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    // destructor
    ~Node()
    {cout << "Deleting node " << data << endl;}
};


void insertAtHead(Node* &head, int d)
{
    // create new node
    Node* temp = new Node(d);
    temp->next = head;
    head=temp;
}


void insertAtTail(Node* &tail, int d)
{
    // create new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail=temp;
}


void insertSomewhere(Node* &head, int pos, int d)
{
    if(pos==0)
        {
            insertAtHead(head, d);
            return;
        }


    Node* temp = head;
    // reach position
    for(int i=0; i<pos-1; i++)
    {
        temp=temp->next;
    }

    // create new node
    Node* newnode = new Node(d);
    newnode->next=temp->next;

    temp->next=newnode;
}


void deleteNode(Node* &head, int pos)
{
    // delete head
    if(pos == 0)
    {
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    Node* prev = head;

    // move to (pos-1)th node
    for(int i=0; i<pos-1; i++)
    {
        if(prev == NULL || prev->next == NULL)
            return;

        prev = prev->next;
    }

    Node* toDelete = prev->next;

    if(toDelete == NULL)
        return;

    prev->next = toDelete->next;
    toDelete->next=NULL;
    delete toDelete;
}


void print(Node* &head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* head = new Node(0);
    print(head);

    Node* tail = head;

    for(int i=1; i<=15; i++)
    {
        insertAtTail(tail, i);
    }
    print(head);


    insertSomewhere(head, 10, 99);
    print(head);


    deleteNode(head, 10);
    print(head);
}