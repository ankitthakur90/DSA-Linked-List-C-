#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev =NULL;
        this->next = NULL;
    }
};

void append(Node* &Head, Node* &Tail, int data){

    Node* temp = new Node(data);

    Node* curr = Head;

    while (curr->next != Head)
    {
        curr = curr->next;
    }

    temp->prev = curr;
    temp->next = curr->next;
    curr->next = temp;
    Tail = temp;
    Head->prev = Tail;
   

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

void addHead(Node* &Head,Node* &Tail ,int data){

    Node* temp = new Node(data);

    temp->prev = Tail;
    temp->next = Head;
    Head->prev = temp;
    Tail->next = temp;
    Head = temp;

}

void insertAtPosition(Node* &Head,Node* &Tail, int pos ,int data){

    if(pos == 1){
        addHead(Head,Tail,data);
        return;
    }

    Node* curr = Head;
    int i = 1;
    while (i <( pos-1))
    {
       curr = curr->next;
       if(curr == Head){
        cout<<" Wrong Position :"<<endl;
        return;
       }
       i++;
    }
 
    if(curr->next == Head){
        append(Head,Tail,data);
        return;
    }

    Node* temp = new Node(data);

   temp->next = curr->next;
   curr->next->prev = temp;

   temp->prev = curr;
   curr->next = temp;

    
}
void deleteAtPosition(Node* &Head , Node* &Tail,int pos){
    if(pos == 1){
        Node* temp = Head;
        Head = Head->next;
        Head->prev = temp->prev;
        Tail->next = Head;

        temp->prev =NULL;
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
        cout<< " wrong position : "<<endl;
        return;
       }
       i++;
    }

    if(curr->next == Head){
        prv->next = curr->next;
        Tail = prv;
        Head->prev = Tail;

        curr->next = NULL;
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
int main(int argc, char const *argv[])
{
    Node* Node1 = new Node(5);
    Node* Head = Node1;
    Node* Tail = Node1;
    Head ->prev = Tail;
    Tail ->next = Head;
    
    append(Head,Tail,10);
  /*   append(Head,Tail,20);
    append(Head,Tail,30);
    addHead(Head,Tail,4);
    addHead(Head,Tail,2); */
    addHead(Head,Tail,0);
    
    insertAtPosition(Head ,Tail,1,01);
    insertAtPosition(Head ,Tail,3,2);
    insertAtPosition(Head ,Tail,6,20);
    insertAtPosition(Head ,Tail,7,30);
    insertAtPosition(Head ,Tail,8,40);
    insertAtPosition(Head ,Tail,9,50);
    insertAtPosition(Head ,Tail,10,60);
    insertAtPosition(Head ,Tail,1,-1);
    addHead(Head,Tail,-2);
    show(Head);
    cout<<endl;

    deleteAtPosition(Head,Tail,1);
    show(Head);

    deleteAtPosition(Head,Tail,3);
    show(Head);

    deleteAtPosition(Head,Tail,10);
    show(Head);
    
    return 0;
}
