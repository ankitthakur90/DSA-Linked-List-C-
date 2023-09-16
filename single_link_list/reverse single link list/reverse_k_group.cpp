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

void ReverseNodes(Node* &head,Node* &curr,Node* &prv , int rev){

    Node* tempCurr = curr;

    Node* prv1 = NULL;
    Node* forward = NULL;
    int i = 0 ;

    while (i < rev)
    {
        forward = curr->next;
        curr->next = prv1;
        prv1 = curr;
        curr = forward;
        i++;
    }

    if(prv == NULL){
     prv = head;
    head->next = curr;
    head = prv1;
   }else{
     prv->next = prv1;
     tempCurr->next = curr;
     prv = tempCurr;
   }

    
    
}

void ReverseLast(Node* &head,Node* &curr,Node* &prv){
    Node* tempCurr = curr;
    Node* prv1 = NULL;
    Node* forward  =  NULL;

    while (curr!=NULL)
    {
       forward = curr->next;
       curr->next = prv1;
       prv1 = curr;
       curr = forward;
    }

    if(prv == NULL){
        head = prv1;
        return;
    }
    prv->next = prv1;
    prv=tempCurr;
    tempCurr->next = NULL;

}
int getLenNode(Node* &head){
    Node* curr = head;
    int count = 0;
    while (curr!=NULL)
    {
        curr = curr->next;
        count++;
    }
    return count;
    
}
Node* getListAfterReverseOperation(Node* &head, int n, int b[]){
    
if(head == NULL){
		return head;
	}


    int lenArr = n;
   

    Node* curr = head;
    Node* prv = NULL;
    int newSize = getLenNode(head);


    for ( int i = 0; i < lenArr; i++)
    {

       int times = b[i];

	   if(times == 0){
		   continue;
	   }
        if(times < newSize){

        ReverseNodes(head,curr,prv,times);
              
        newSize = newSize-times;

       }
       else if(newSize < times){

        ReverseLast(head,curr,prv);
        newSize = 0;
       }
	    if(newSize == 0){
        return head;
       }


    }

	return  head;

    
}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(1);
   
    Node *head = Node1;
    Node *tail = Node1;

    // cout<<Head->data<<endl;
    // cout<<tail->data<<endl;

    append(head,tail,2);
    
    append(head,tail,3);
    append(head,tail,4);
    append(head,tail,5);


    show(head);
    
    int arr[5] = {3,3,5};

    getListAfterReverseOperation(head,3,arr);

 // cout<<sizeof(arr);

    


    
    return 0;
}
