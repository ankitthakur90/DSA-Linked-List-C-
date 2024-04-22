#include <iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void append(ListNode *&head, int data)
{

    ListNode *temp = new ListNode(data);

    ListNode *curr = head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }
    curr->next = temp;

    temp->next = NULL;
}

void show(ListNode *&head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
ListNode * solve(ListNode * &head){
   ListNode * curr = head;
   ListNode * frw = NULL;
    
   while(curr->next != NULL && curr->next->next != NULL){
        ListNode * prv = NULL;
        ListNode * temp = curr->next;
       frw = curr->next;
       while(temp->next != NULL){
           prv = temp;
           temp =temp->next;
       }
        prv->next = NULL;
       curr->next = temp;
       curr= curr->next;
       curr->next = frw;
       curr = curr->next;
   }
   return head;
}
ListNode * rearrangeList(ListNode * head)
{
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head;
    }

    return solve(head);
}


int main(int argc, char const *argv[])
{
    ListNode *ListNode1 = new ListNode(1);

    ListNode *head = ListNode1;
    head->next = NULL;

    append(head, 2);

    append(head, 3);
    append(head,4);
    append(head,5);
    append(head,6);
    show(head);
     rearrangeList(head);
    show(head);


    return 0;
}