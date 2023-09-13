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
   
   temp->next = NULL;



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

int getLength(Node* &Head){
    Node* curr = Head;
    int counter = 0;

    while (curr!= NULL)
    {
       curr = curr->next;
       counter++;
    }
    return counter;
    
}
Node* rotatedList(Node* &Head , int k ){

    int timesOfRotate = k % getLength(Head);
    cout<<getLength(Head)<< " "<<timesOfRotate<<endl;
    int timeCounter = 0;

    while (timeCounter < timesOfRotate)
    {
        Node* curr = Head;
        Node* prv = NULL;
        while (curr->next!=NULL)
        {
            prv = curr;
            curr  = curr->next;
        }

        prv->next = NULL;
        curr ->next = Head;

        Head = curr;

        timeCounter++;
        
    }

    return Head;
    

}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(1);
   
    Node *Head = Node1;
    Head->next = NULL;

    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    append(Head,2);
    
    append(Head,3);
    append(Head,4);
    append(Head,5);
    append(Head,6);
    


    show(Head);

    Head = rotatedList(Head, 2);

    show(Head);

  
    
    return 0;
    
}