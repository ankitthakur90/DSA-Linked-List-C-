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

int getLength(Node* &Head){
    Node* curr = Head;

    int cnt = 0;
    while (curr!= NULL)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
    
}

Node* middleNode(Node* &Head){
    int len = getLength(Head)/2;
    
    int cnt = 0 ;
    while (cnt < len)
    {
        Head = Head->next;
        cnt++;
    }

    return Head;
    
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
    append(Head,70);
    show(Head);

    Head = middleNode(Head);
    show(Head);


    return 0;
}
