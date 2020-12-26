//Linked List
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link;

    node()
    {
        data = 0;
        link = NULL;
    }
} * head;

int countLinkedList(node *head)
{
    int count = 0;
    if (head == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
        // cout<<"\nno of node is : "<<count<<endl;
    }
    return count;
}

node *delHead(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty ";
    }
    else
    {
        node *temp = head;
        head = head->link;
        delete[] temp;
    }
    return head;
}

void printData(node *head)
{
    if (head == NULL)
        cout << "Linked List is empty! ";
    else
    {
        node *ptr = NULL;
        ptr = head;
        cout << "linked List elements are : ";
        while (ptr != NULL)
        {
            cout << ptr->data << " --> ";
            ptr = ptr->link;
        }
        cout << "NULL";
        cout << endl;
    }
}

void create(int a[], int n)
{
    int i;
    node *temp, *ptr;
    if (n == 0)
    {
        cout << "Linked List is Empty!" << endl;
    }
    else
    {
        temp = new node();
        temp->data = a[0];
        temp->link = NULL;
        head = temp;
        ptr = temp;
        for (i = 1; i < n; i++)
        {
            temp = new node();
            temp->data = a[i];
            temp->link = NULL;
            ptr->link = temp;
            ptr = temp;
        }
    }
}

node *delPos(node *head, int size, int n)
{
    int i;
    if (n < 1 || n > size)
    {
        return head;
    }
    else if (n == 1)
    {
        head = delHead(head);
    }
    else
    {
        node *temp, *ptr;
        ptr = head;
        for (i = 0; i < n - 2; i++)
        {
            ptr = ptr->link;
        }
        temp = ptr->link;
        ptr->link = temp->link;
        delete[] temp;
    }
    return head;
}

node *revList(node *head)
{
    node *prev, *next;
    prev = NULL;
    next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

node *delList(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty!";
    }
    else
    {
        node *temp;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->link;
            delete[] head;
            head = temp;
        }
    }

    return head;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    create(a, n);
    printData(head);
    int size = countLinkedList(head);
    head = delPos(head, size, 5);
    printData(head);
    head = revList(head);
    printData(head);
    head = delList(head);
    printData(head);

    return 0;
}
