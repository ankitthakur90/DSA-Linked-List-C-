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

Node* deleteNodesOnRegularInterval(int a, int b, Node* head) {
    Node* curr = head;
   Node* prev  =curr;
   Node* forewrd = NULL;
    
   if(head->next == NULL){
       return  head;
   }
    while(curr != NULL){

        int i = 0;
        while((i < a) && ( curr != NULL)){
            prev = curr;
            curr = curr->next;
            i++;
        }

        int j = 0;

        while ((j < b) && ( curr != NULL))
        {
            forewrd = curr->next;
            prev ->next = curr->next;
            curr->next = NULL;
            free(curr);
            curr = forewrd;
            j++;

        }

        if(curr == NULL){
            return head;
        }
        


    }
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
    append(Head,7);

   

    show(Head);
   Head =  deleteNodesOnRegularInterval(2,3,Head);
    show(Head);

    


    
    return 0;
}