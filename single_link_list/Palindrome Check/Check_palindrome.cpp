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

    show(Head);

    


    
    return 0;
}
