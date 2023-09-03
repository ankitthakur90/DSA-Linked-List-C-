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

Node* reverse(Node* &Head){

    if(Head == NULL || Head->next == NULL){
        return Head;
    }
    Node* curr = Head;
    Node* prv = NULL;
    Node* forward = NULL;

    while (curr!=NULL)
    {
       forward = curr->next;

       curr->next = prv;
       curr ->prev = forward;
       prv = curr;
       curr = forward;
    }

    return prv;
    
}

int main(int argc, char const *argv[])
{

    Node *Node1 = new Node(5);
    Node *Head = Node1;
    Node *Tail = Node1;

    append(Head,Tail,10);
    append(Head,Tail,20);
    append(Head,Tail,30);
    append(Head,Tail,60);
    append(Head,Tail,70);
    append(Head,Tail,80);
    display(Head);
   Head = reverse(Head);
   display(Head);
    return 0;
}
