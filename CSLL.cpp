// Circular Singly Linked List
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

node *createCSLL(node *head, int a[], int n)
{
    node *temp = new node();
    temp->data = a[0];
    temp->next = temp;
    head = temp;
    node *ptr = head;

    for (int i = 1; i < n; i++)
    {
        node *temp = new node();
        temp->data = a[i];
        temp->next = head;
        ptr->next = temp;
        ptr = temp;
    }

    return head;
}

node *addAtBeg(node *head, int data)
{
    node *temp = new node();
    node *ptr = head;
    temp->data = data;
    temp->next = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    head = temp;
    return head;
}

node *addAtEnd(node *head, int data)
{
    if (head == NULL)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = temp;
        head = temp;
    }
    else
    {
        node *ptr = head;
        node *temp = new node();
        temp->data = data;
        temp->next = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    return head;
}

node *addAtPos(node *head, int data, int pos)
{
    node *p = head, *q, *temp = new node();
    if (pos == 1)
    {
        head = addAtBeg(head, data);
        return head;
    }
    temp->data = data;
    while (pos != 2)
    {
        p = p->next;
        pos--;
    }
    q = p->next;
    p->next = temp;
    temp->next = q;
    return head;
}

node *delBeg(node *head)
{
    node *q = head;

    while (q->next != head)
    {
        q = q->next;
    }
    q->next = head->next;
    delete head;
    head = q->next;
    return head;
}

node *delEnd(node *head)
{
    node *p = head;
    while (p->next->next != head)
    {
        p = p->next;
    }
    delete (p->next);
    p->next = head;
    return head;
}

node *delPos(node *head, int pos)
{
    node *p = head, *q = NULL;
    if (pos == 1)
    {
        head = delBeg(head);
    }
    else
    {
        while (pos != 2)
        {
            p = p->next;
            pos--;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        q = NULL;
    }
    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "CSLL is empty! ";
    }
    else
    {
        node *ptr = head;
        while (ptr->next != head)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << " ";
        cout << endl;
    }
}

int main()
{
    node *head = NULL;
    int a[] = {5, 4, 7, 23, 65, 44, 96, 30, 73, 2, 66};
    int size = sizeof(a) / sizeof(a[0]);
    head = createCSLL(head, a, size);
    head = addAtEnd(head, 5);
    head = addAtEnd(head, 10);
    head = addAtEnd(head, 15);
    display(head);
    head = addAtBeg(head, 55);
    display(head);
    head = addAtPos(head, 99, 6);
    display(head);
    head = delEnd(head);
    display(head);
    head = delBeg(head);
    display(head);
    head = delPos(head, 5);
    display(head);

    return 0;
}
