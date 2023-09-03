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


Node* KNodeReverse(Node* Head , int k ){
    
    // step -1 
    if(Head == NULL){
        return Head;
    }
    
    // step -> 2 

    Node* curr = Head;
    Node* prv = NULL;
    Node* forward = NULL;

    int cnt = 0;

    while (cnt < k && curr!=NULL)
    {
        forward = curr->next;
        curr ->next = prv;
        prv = curr;
        curr = forward;
        cnt++;
    }


    // step -> 3 

    // check forward has  null or not
    if(forward!= NULL){
       Head ->next = KNodeReverse(forward,k);
    }

    return prv;



}

int checkLenght(Node* Head){
    Node* curr = Head;
   
   int  cnt =  0 ;
    while (curr!= NULL)
    {
        cnt++;
        curr = curr->next;
    }

    return cnt;
    
}


Node* KNodeReverseParticular(Node * &Head,int k){

     // step -1 
    if(Head == NULL){
        return Head;
    }
    
    // step -> 2 

    Node* curr = Head;
    Node* prv = NULL;
    Node* forward = NULL;

    int cnt = 0;

    while (cnt < k && curr!=NULL)
    {
        forward = curr->next;
        curr ->next = prv;
        prv = curr;
        curr = forward;
        cnt++;
    }


    // step -> 3 

    // check forward has  null or not

    int temp = checkLenght(forward) - k;

    if(temp<0){

        Head->next = forward;
        return prv;

    }
    else if(forward!= NULL){
       Head ->next = KNodeReverse(forward,k);
    }

    return prv;
}


int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   
    Node *Head = Node1;
    Node *tail = Node1;

    append(Head,tail,8);
    
    append(Head, tail,10);
    append(Head , tail,20);
    append(Head , tail,30);
    append(Head , tail,40);
    append(Head , tail,70);
    show(Head);

   // Head = KNodeReverse(Head,7);
    Head = KNodeReverseParticular(Head,6);
    show(Head);
    return 0;
}
