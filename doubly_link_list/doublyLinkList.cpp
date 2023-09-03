#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

};
void append(Node* &Head,Node* &Tail,int data){
    Node* temp = new Node(data);
    if(Head == NULL){
        Head = temp;
        Head->prev = NULL;
        Head ->next = NULL;
        Tail = temp;
        return;

    }

    Node* curr = Head;
    while (curr->next!=NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    temp->next = NULL;
    Tail = temp;
    
}

void display(Node* &Head){
    if(Head == NULL){
        cout<<" NO List Available"<<endl;
        return;
    }
    Node* curr = Head;

    while (curr!=NULL)
    {
       cout<<curr->data<< " ";
       curr = curr ->next;
    }
    cout<<endl;

    
}

void insertAtHead(Node* &Head,int data){
    Node* temp = new Node(data);

     Head->prev = temp;
     temp->next = Head;
     Head = temp;
     
}
void insertAtPosition(Node* &Head , Node* &Tail,int pos ,int data){
    if(pos == 1){
        insertAtHead(Head,data);
        return;
    }

    Node* curr = Head;
    
    int i = 1;
    while (i < pos - 1)
    {
       curr = curr->next;
       if(curr == NULL){
        cout<<" Wrong position "<<endl;
        return;
       }
       i++;
    }
    if(curr->next == NULL){
        append(Head,Tail,data);
        return;
    }

    Node* temp = new Node(data);

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
    
}

void deleteNode(Node* &Head , Node* &Tail,int pos){
    if(pos == 1){
        Node* temp = Head;
        Head = Head->next;
        Head ->prev = NULL;
        temp->next = NULL;
        free(temp);
        return;
    }

    Node* curr = Head;
    Node* prv = curr;
    int i= 1;

    while (i < pos)
    {
        prv = curr;
        curr = curr->next;
        if(curr == NULL){
            cout<< " Wrong Position : "<<endl;
            return;
        }
        i++;
    }
    
    if(curr->next == NULL){
        Tail = prv;
        prv->next = NULL;
        curr->prev = NULL;
        free(curr);
        return;
    }

    prv->next = curr->next;
    curr->next->prev = prv;

    curr->next = NULL;
    curr->prev = NULL;
    free(curr);

}

void rev(Node* curr){
  
    if(curr->next == NULL){
        return;
    }
    Node* pr = curr;
    rev(curr->next);
    
   cout<<pr->data<<" ";
}
int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
    Node *Head = Node1;
    Node *Tail = Node1;

    append(Head,Tail,10);
    append(Head,Tail,20);
    append(Head,Tail,30);
    insertAtHead(Head,4);
    insertAtHead(Head,3);
    insertAtHead(Head,2);
    insertAtPosition(Head,Tail,5,6);
    insertAtPosition(Head,Tail,6,7);
    insertAtPosition(Head,Tail,10,40);
    insertAtPosition(Head,Tail,1,1);
    append(Head,Tail,50);
    insertAtHead(Head,0);
    display(Head);

    deleteNode(Head,Tail,9);
 


    display(Head);
    cout<<endl;
    rev(Head);

   


   
    return 0;
}
