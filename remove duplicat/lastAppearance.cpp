#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>

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

Node* reverse(Node* &head){

    
    Node* curr = head;
    Node* prv = NULL;
    Node* forward = NULL;

    while (curr!=NULL)
    {
       forward = curr->next;

       curr->next = prv;

       prv = curr;
       curr = forward;
    }

    return prv;
    
}

Node* removeDuplicat(Node* Head){
    if(Head == NULL){
        return NULL;
    }
    if(Head->next == NULL){
        return Head;
    }

    Node* curr = Head;
    Node* prv  = NULL;
    unordered_map<int , bool> visited;

    while (curr!=NULL)
    {
        if(visited[curr->data] == true){
           if(curr->next == NULL){
                prv->next = NULL;
                free(curr);
                return Head;
            }else{
            Node* temp = curr->next;
            prv->next = temp;
            curr->next = NULL;
            free(curr);
            curr = temp;

            }
        }else{
        visited[curr->data] = true;
        prv = curr;
        curr = curr->next;
        }
    }

    return Head;
    
}

int main(int argc, char const *argv[])
{
  Node *Node1 = new Node(13);
   
    Node *Head = Node1;
    Head->next = NULL;



    append(Head,1);
    append(Head,19);
    
    append(Head,3);
    append(Head,9);
    
    show(Head);

   
   Head = reverse(Head);
    show(Head);
   Head = removeDuplicat(Head);
   show(Head);
   Head = reverse(Head);
   show(Head);

   

    


    
    return 0;
}
