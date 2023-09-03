#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this ->next = NULL;
    }
};

void append(Node* &Head,Node* &Tail,int data){
    Node* temp = new Node(data);
    Node* curr = Head;

    while (curr->next!=Head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = Head;
    Tail = temp;
    
}

void addHead(Node* &Head,Node* &Tail ,int data){

    Node* temp = new Node(data);

    temp->next = Head;
    Head = temp;
    Tail->next = Head;


}

void show(Node* &Head){

    Node* curr = Head;

    while (1)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
        if(curr == Head){
            cout<<endl;
            return;
        }
    }
    
}
void addAtPosition(Node* &Head ,Node* &Tail,int pos ,int data){

    if(pos == 1){
        addHead(Head, Tail ,data);
        return;
    }

    Node* curr = Head;
    int i = 1;
    while (i < pos-1)
    {
        curr = curr->next;
        if(curr == Head){
            cout<<" Wrong Position : "<<endl;
            return;
        }
        i++;
    }
    
    if(curr->next == Head){
        append(Head,Tail,data);
        return;
    }
     Node* temp = new Node(data);
    temp->next  = curr->next;
    curr->next = temp;

}
void deleteNodeAtPosition(Node* &Head, Node* &Tail,int pos){
    if(pos == 1){
        Node* temp = Head;
        Head = Head->next;
        Tail->next = Head;
        temp->next = NULL;
        free(temp);
        return;
    }

    Node* curr = Head;
    Node* prv = curr;
    int i = 1;

    while (i < pos)
    {
       prv = curr;
       curr = curr->next;
       if(curr == Head){
        cout<<" Wrong Position : "<<endl;
        return;
       }
       i++;
    }
    if(curr->next == Head){
        Tail = prv;
    }
    prv->next = curr->next;
    curr->next = NULL;
    free(curr);
    
}
int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   

    Node* Head = Node1;
    Node1->next = Head;
    Node* Tail = Node1;
    
    append(Head ,Tail,10);
    append(Head ,Tail,20);
    append(Head ,Tail,30);
    append(Head ,Tail,40);
    append(Head ,Tail,60);
    append(Head ,Tail,70);
    append(Head ,Tail,80);
    append(Head ,Tail,90);
    addHead(Head,Tail , 4);
    addHead(Head,Tail , 3);
    addAtPosition(Head,Tail,4,6);
    addAtPosition(Head,Tail,5,7);
    addAtPosition(Head,Tail,14,100);
    addAtPosition(Head,Tail,1,2);
    addAtPosition(Head,Tail,1,1);
    show(Head);


    deleteNodeAtPosition(Head,Tail,1);
    deleteNodeAtPosition(Head,Tail,6);
    deleteNodeAtPosition(Head,Tail,14);

    show(Head);




    return 0;
}
