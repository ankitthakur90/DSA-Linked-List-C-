#include<iostream>
#include<map>

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

    Node* detectLoop(Node* Head){

    Node* rabbit = Head;
    Node* tortoise = Head;

    while (rabbit!= NULL && tortoise!=NULL)
    {
        if(rabbit->next == NULL || rabbit->next->next == NULL){
            return NULL;
        }
        rabbit = rabbit->next;
    
        rabbit = rabbit->next;

        tortoise = tortoise->next;


        if(rabbit == tortoise){
            return rabbit;
        }
        
    }

    return NULL;
    }


void removeLoop(Node* Head){
    if(Head == NULL){
        return;
    }

    Node* insection = detectLoop(Head);
    Node* slow = Head;

    while (slow != insection)
    {
        slow = slow->next;
      
        if(insection->next == slow){
            insection ->next = NULL;
            return;
        }
       
        insection = insection->next;
    }

}



int main(int argc, char const *argv[])
{
    Node *Head = new Node(5);
   
   
    Node *tail = Head;

    

    append(Head,tail,8);
    append(Head,tail,10);
    append(Head,tail,20);
    append(Head,tail,30);
    append(Head,tail,40);
    append(Head,tail,50);
    

  tail->next = Head->next; // This will create cycle 
    //show(Head);
    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    if(detectLoop(Head)){
        cout<<" Cycle Is Present! "<<endl;
    }
    else{
        cout<<" Cycle Not Is Present! "<<endl;
    }

    removeLoop(Head);
      show(Head);



    return 0;
}
