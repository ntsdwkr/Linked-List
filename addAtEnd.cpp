//add node at the end of Linked List
#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node *link;
};

void addAtEnd(node *head,int data){
    if(head==NULL){
        head->data=data;
        head->link=NULL;
    }
    else{
        node *ptr,*temp;
        ptr=head;
        temp=new node();
        temp->data=data;
        temp->link=NULL;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}

void printData(node *head){
    if(head==NULL) cout<<"Linked List is empty ";
    else{
        node *ptr=NULL;
        ptr=head;
        cout<<"linked List elements are : "; 
        while(ptr!=NULL){
            cout<<ptr->data<<" "; 
            ptr=ptr->link;
        }
    }
}

void countLinkedList(node *head){
    int count=0;
    if(head==NULL){
        cout<<"Linked List is empty";
    }
    else{
        node *ptr=NULL;
        ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->link;
        }
        cout<<"\nno of node is : "<<count<<endl;
    }
}

int main(){
    node *head=new node();
    head->data=45;
    head->link=NULL;

    node *current=new node();
    current->data=98;
    current->link=NULL;
    head->link=current;
    
    current=new node();
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    countLinkedList(head);
    printData(head);

    addAtEnd(head,67);
    addAtEnd(head,25);
    countLinkedList(head);
    printData(head);


    return 0;
}
