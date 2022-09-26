/*
In this we have given a Node a property called visited which tells us that whether we have visited that node or not
*/
#include <iostream>

class Node
{
public:
    int data;
    bool visited;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->visited = false;
    }
};

using namespace std;

Node *takeinput()
{
    int data;
    cout << "Enter the Linked List :" << endl;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    tail->next = head;
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp->visited != true)
    {
        if (temp->next->visited != true)
        {
            cout << temp->data << " -> ";
        }
        else
        {
            cout << temp->data;
        }
        temp->visited = true;
        temp = temp->next;
    }
    cout << endl;
    cout << "We have reached the start of the Circular Linked List" << endl;
}

int main()
{
    Node *head = takeinput();
    print(head);
    return 0;
}