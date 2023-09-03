#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this ->next = NULL;
    }
};

void append(Node* &Head,Node* &Tail,int data){
    Node* temp = new Node(data);
    Node* curr = Head;

    while (curr->next!=Head)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = Head;
    Tail = temp;
    
}

void show(Node* &Head){

    Node* curr = Head;

    while (1)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
        if(curr == Head){
            cout<<endl;
            return;
        }
    }
    
}

int getLength(Node* Head){
     Node* curr = Head;
    
    int cnt = 0;
    while (1)
    {
        cnt++;
        curr = curr->next;
        if(curr == Head){
            break;
        }
    }
    return cnt;
}

void twoPartitionOfCircularLinklist(Node* Head){

    if(Head == NULL){
        return;
    }

    Node* curr = Head;

    int counter = getLength(Head)/2;
    int nodeAddCounter = 0;
    if(getLength(Head)%2 != 0){
        counter++;
    }
    while (nodeAddCounter < (counter) -1)
    {
        curr = curr->next;
        nodeAddCounter++;
    }

    Node* Head2 = curr->next;
    curr->next = Head;

    Node* curr2 = Head2;

    while (curr2->next!=Head)
    {
        curr2 = curr2->next;

    }

    curr2->next = Head2;


     show(Head);
     show(Head2);
    
}


int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
   

    Node* Head = Node1;
    Node1->next = Head;
    Node* Tail = Node1;
    
    append(Head ,Tail,10);

  

    show(Head);
    
    cout<<endl;

    cout<<Head->data<<" "<<Tail->data<<" "<<endl;

  twoPartitionOfCircularLinklist(Head);

    return 0;
}

