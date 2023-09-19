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
Node* revesrNodes(Node* &curr , int i , int high){

	Node* curr1 = curr;
	Node* forward = NULL;
	Node* prve = NULL;

	while((i <= high) &&( curr1!= NULL) ){
		forward  = curr1->next;
		curr1->next = prve;
		prve = curr1;
		curr1 = forward;
		i++;
	}

	curr->next = curr1;
	return prve;
	
}

Node *reverseLL(Node *head, int low, int high) {
	// Write your code here.

	if(head ->next == NULL){
		return NULL;
	}

	if(head->next == NULL){
		return  head;
	}

	if(low == high){
		return head;
	}

    int i  = 1 ; 

	Node* curr = head;
	Node* prv = head;


	while( i < low){
		prv = curr;
        curr = curr->next;
		i++;
	}
    
   if(low != 1){
   prv->next =  revesrNodes(curr, i , high);
    return head;
    }
   else{
    return revesrNodes(curr, i , high);
   }


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

 Head =   reverseLL(Head,1,5);
    show(Head);
    return 0;
}
