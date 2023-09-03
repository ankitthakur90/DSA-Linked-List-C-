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

void append(Node* &Head,int data){

   Node* temp = new Node(data);

   Node* curr = Head;

   while (curr->next != NULL)
   {
  
     curr = curr ->next;

   }
   curr->next = temp;

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

Node* reverseNode(Node* &Head){

    if(Head == NULL || Head->next == NULL){
        return Head;
    }

    Node* temp = reverseNode(Head->next);

    Head->next->next = Head;
    Head->next = NULL;
   
   return temp;


}

int main(int argc, char const *argv[])
{
    Node* Node1 = new Node(5);

    Node* Head = Node1;
    Node* Tail = Node1;
    append(Head,10);
    append(Head,20);
    append(Head,30);
    append(Head,40);
    append(Head,50);
    append(Head,60);
    show(Head);

    Head =  reverseNode(Head);
    show(Head);

    


    return 0;
}
