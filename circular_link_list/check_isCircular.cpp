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

bool isCircular(Node* &Head){
    Node* curr = Head;

    while (1)
    {
       if(curr->next == NULL){
        return false;
       }
       if(curr->next == Head){
        return true;
       }
    }
    
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
    show(Head);
    cout<<isCircular(Head)<<endl;
    return 0;
}
