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


void printReverse(Node* Head){

    if((Head == NULL )){
        return;
    }

    printReverse(Head->next);
    cout<<Head->data<<" ";
}


int main(int argc, char const *argv[])
{
    Node* Head = new Node(10);

    append(Head,20);
    append(Head,30);
    append(Head,40);
    append(Head,50);
    show(Head);
    
    printReverse(Head);
    return 0;
}
