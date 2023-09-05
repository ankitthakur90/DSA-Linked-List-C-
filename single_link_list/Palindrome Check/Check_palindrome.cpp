#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/submissions/

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
   Node* reverseList(Node* head){
        Node* curr = head;
        Node* forword = NULL;
        Node* prev  = NULL;

        while(curr!= NULL){
            forword = curr->next;
            curr->next = prev;
            prev = curr;
            curr  = forword;
        }
        return prev;
   }
    bool isPalindrome(Node* head) {
        if(head == NULL){
            return false;
        }
        if(head->next == NULL){
            return true;
        }
        
        vector<int> ans;
        
        Node* curr = head;

        while (curr!=NULL)
        {
            int value = curr->data;
            ans.push_back(value);
            curr = curr->next;

        }
        curr = head;
        reverse(ans.begin(),ans.end());
        int i = 0 ;
        while (curr!=NULL)
        {
            int value = curr->data;
            if(value != ans[i] ){
                return false;
            }
            i++;
            curr = curr->next;

        }

        return true;
        
    }
int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(1);
   
    Node *Head = Node1;
    Node *tail = Node1;
    
    append(Head,tail,1);
    append(Head,tail,2);

    append(Head,tail,1);
  
   

    show(Head);

    cout<<isPalindrome(Head);

    


    
    return 0;
}
