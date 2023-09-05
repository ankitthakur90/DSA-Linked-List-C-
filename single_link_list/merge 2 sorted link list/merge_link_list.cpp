#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

};
void append(Node* &Head,Node* &tail,int data){

   Node* temp = new Node(data);

   Node* curr = Head;

   while (curr->next != NULL)
   {
  
     curr = curr ->next;

   }
   curr->next = temp;

   tail = temp;

}



void show(Node* &Head){
    Node* curr = Head;

    while (curr!=NULL)
    {
       cout<<curr->data<<" ";
       curr = curr->next;
    }
    cout<<endl;
    
}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   
    Node *Head = Node1;
    Node *tail = Node1;

    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    append(Head,tail,8);
    
    append(Head,tail,10);


    addHead(Head,4);
   
    addHead(Head,2);

    insertAtPos(Head,4,6);
    insertAtPos(Head,5,7);
    insertAtPos(Head,2,3);
    insertAtPos(Head,1,1);
    insertAtPos(Head,9,9);
    insertAtPos(Head,11,11);
    insertAtPos(Head,13,12);

    update(Head,1,0);

    update(Head,6,666);

    deleteLinkList(Head,tail,6);
    deleteLinkList(Head,tail,1);
 //   deleteLinkList(Head,tail,10);
    deleteLinkList(Head,tail,9);

    show(Head);

    


    
    return 0;
}
