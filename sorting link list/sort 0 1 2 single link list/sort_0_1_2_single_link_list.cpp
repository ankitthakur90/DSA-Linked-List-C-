#include<iostream>
#include<vector>
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

void getCount(vector<int>  &counter , Node* Head){
   Node * curr  = Head;
   int count0 =  0 , count1 = 0,count2 = 0;

   while (curr!=NULL)
   {

    if(curr->data == 0){
        count0++;
    }
    else if(curr->data == 1){
        count1++;
    }
    else if(curr->data == 2){
        count2++;
    }
     curr = curr->next;
      
   }

   counter.push_back(count0);
   counter.push_back(count1);
   counter.push_back(count2);
   
}

Node* sort012(Node* Head){
    vector<int> counter;

    getCount(counter,Head);
     int count0 =  counter[0], count1 = counter[1],count2 = counter[2];

    int mainCounter = 0 ;

    Node* curr = Head;

    while (mainCounter < count0)
    {
        curr->data = 0;
        curr = curr->next;
        mainCounter++;
    }


    mainCounter = 0 ;

     while (mainCounter < count1)
    {
        curr->data = 1;
        curr = curr->next;
        mainCounter++;
    }
    mainCounter = 0 ;

     while (mainCounter < count2)
    {
        curr->data = 2;
        if(curr->next == NULL){
            return Head;
        }
        curr = curr->next;
        mainCounter++;
    }

    return Head;


}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(0);
   
    Node *Head = Node1;
    Node *tail = Node1;

    append(Head,tail,1);
    
    append(Head,tail,1);
    append(Head,tail,1);
    append(Head,tail,1);
    append(Head,tail,2);
    append(Head,tail,2);
    append(Head,tail,1);
    append(Head,tail,0);
    append(Head,tail,0);
    append(Head,tail,2);
    append(Head,tail,1);

    show(Head);

    sort012(Head);

    Head = sort012(Head);

    show(Head);

    
    return 0;
}
