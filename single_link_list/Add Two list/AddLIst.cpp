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

    if(Head == NULL){
       Head = temp;
       tail = Head;
       return ;
    }
 

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


Node* reverse(Node* &Head){

    if(Head == NULL || Head->next == NULL){
        return NULL;
    }
    
    Node* curr = Head;
    Node* prv = NULL;
    Node* forward = NULL;

    while (curr!=NULL)
    {
       forward = curr->next;

       curr->next = prv;

       prv = curr;
       curr = forward;
    }

    return  prv;
    
}

Node* addList(Node* Head1 , Node* Head2){

    Node* curr1 = reverse(Head1);
    Node* curr2  = reverse(Head2);

   Node* ansHead = NULL;
   Node* ansTail = NULL;
   
   int carry = 0;
   while (curr1 != NULL && curr2 !=NULL)
   {
       int sum =  carry + curr1->data + curr2->data;
       int digit = sum%10;
       append(ansHead,ansTail, digit);
       carry = sum/10;
       curr1 = curr1->next;
       curr2 = curr2 ->next;
   }

   while (curr1 != NULL)
   {
    int sum =  carry + curr1->data ;
       int digit = sum%10;
       append(ansHead,ansTail, digit);
       carry = sum/10;
       curr1 = curr1->next;
     
   }
   while (curr2 != NULL)
   {
    int sum =  carry + curr2->data ;
       int digit = sum%10;
       append(ansHead,ansTail, digit);
       carry = sum/10;
       curr2 = curr1->next;
   }

   while (carry != 0)
   {
    int sum =  carry;
       int digit = sum%10;
       append(ansHead,ansTail, digit);
       carry = sum/10;
   }

  ansHead =   reverse(ansHead);
  return ansHead;


}

int main(int argc, char const *argv[])
{
    Node *Head1 = new Node(99);
   
    Node *tail = Head1;

    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    append(Head1,tail,10);
    
    append(Head1,tail,12);

    Node *Head2 = new Node(23);

    append(Head2,tail,99);

   
    show(Head1);
    show(Head2);

  Node* newHead =   addList(Head1,Head2);

    show(newHead);

    


    
    return 0;
}