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

Node* detectStartingLoopNode(Node* Head){

    Node* curr = Head;
    map<Node*,bool> visited;

    while (curr!=NULL)
    {
        if(visited[curr] == true){
            return curr;
        }
        visited[curr] = true;
        curr =curr->next;
    }
    
    return Head;
}




int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   
    Node *Head = Node1;
    Node *tail = Node1;

    

    append(Head,tail,8);
    append(Head,tail,10);
    append(Head,tail,20);
    append(Head,tail,30);
    append(Head,tail,40);
    append(Head,tail,50);
    

  tail->next = Head->next; // This will create cycle 
   // show(Head);
    cout<<Head->data<<endl;
    cout<<tail->data<<endl;

    
    Node *temp = detectStartingLoopNode(Head);

    cout<<temp->data;


    return 0;
}
