// doubly linked list
#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;

    node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }
};

node *createDLL(int a[], int n)
{
    node *head = new node();
    head->data = a[0];
    node *p = head;
    for (int i = 1; i < n; i++)
    {
        node *temp = new node();
        temp->data = a[i];
        p->next = temp;
        temp->prev = p;
        p = p->next;
    }
    return head;
}

void Display(node *head)
{
    if (head == NULL)
        cout << "Linked List is Empty! ";
    else
    {
        node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

node *delF(node *head)
{
    if (head == NULL)
    {
        cout << "DLL is empty!";
    }
    else
    {
        head = head->next;
        delete[] head->prev;
        head->prev = NULL;
    }
    return head;
}

node *delL(node *head)
{
    if (head == NULL)
    {
        cout << "DLL is empty! ";
    }
    else
    {
        node *p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        delete[] p->next;
        p->next = NULL;
    }
    return head;
}

node *delPos(node *head, int pos)
{
    node *p = head;
    if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        delete p;
        p = NULL;
    }
    else
    {
        while (pos != 1)
        {
            p = p->next;
            pos--;
        }
        if (p->next == NULL)
        {
            p->prev->next = NULL;
            delete p;
            p = NULL;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            p = NULL;
        }
    }

    return head;
}

node *revDLL(node *head)
{
    node *p1 = head;
    node *p2 = p1->next;
    p1->next = p1->prev;
    p1->prev = p1->next;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    return head;
}

int main()
{
    node *head = NULL;
    int a[] = {5, 7, 10, 15, 2, 0, 25, 33, 13, 99, 75};
    int s = sizeof(a) / sizeof(a[0]);
    head = createDLL(a, s);
    Display(head);
    head = delF(head);
    Display(head);
    head = delL(head);
    Display(head);
    head = delPos(head, 5);
    Display(head);
    head = revDLL(head);
    Display(head);

    return 0;
}
