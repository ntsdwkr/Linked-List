//Linked List - inserting node at diffrent postions,traversing,counting
#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node *link;
    node(){
        data=0;
        link=NULL;
    }
};

node *addAtBeg(node *head,int data){
    if(head==NULL){
        head->data=data;
        head->link=NULL;
    }
    else{
        node *ptr=new node();
        ptr->data=data;
        ptr->link=NULL;

        ptr->link=head;
        head=ptr;
    }
    return head;
}

node *addAtPos(node *head,int data,int pos){
    if(pos==1){
        head=addAtBeg(head,data); // if position is 1st the calling addAtBeg
        return head;
    }
    else{
    node *ptr=head;
    node *temp=new node();
    temp->data=data;
    temp->link=NULL;

    while(pos!=2){
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link; 
    ptr->link=temp;
    }
    return head;
}

node *addAtEndOp(node *ptr,int data){
    if(ptr==NULL){
        ptr->data=data;
        ptr->link=NULL;
    }
    else{
    node *temp=new node();
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    ptr=temp;
    }
    return ptr;
}

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
    if(head==NULL) cout<<"Linked List is empty"<<endl;
    else{
        node *ptr=NULL;
        ptr=head;
        cout<<"linked List elements are : "; 
        while(ptr!=NULL){
            cout<<ptr->data<<" "; 
            ptr=ptr->link;
        }
        cout<<endl;
    }
}

void countLinkedList(node *head){
    int count=0;
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
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

    node *ptr=head;
    ptr=addAtEndOp(ptr,98);
    ptr=addAtEndOp(ptr,3);    
    ptr=addAtEndOp(ptr,67);    
    ptr=addAtEndOp(ptr,25);    

    ptr=head; //initialise ptr

    countLinkedList(head);
    printData(head);

    addAtEnd(head,65); 
    addAtEnd(head,25);

    countLinkedList(head);
    printData(head);

    head=addAtBeg(head,87);
    head=addAtBeg(head,42); 

    ptr=head; //initialise ptr

    countLinkedList(head);
    printData(head);

    int d=999;
    int pos=5; 
    head=addAtPos(head,d,pos); 

    ptr=head;

    countLinkedList(head);
    printData(head);

    return 0;
}
