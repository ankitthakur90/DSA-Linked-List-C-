#include<iostream>
#include<bits/stdc++.h>
#include <unordered_map>
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
    Node *Node1 = new Node(5);
   
    Node *Head = Node1;
    Node *tail = Node1;

    append(Head,tail,30);
    append(Head,tail,20);

  
    show(Head);

    Head = removeDuplicat(Head);
    show(Head);

    


    
    return 0;
}
