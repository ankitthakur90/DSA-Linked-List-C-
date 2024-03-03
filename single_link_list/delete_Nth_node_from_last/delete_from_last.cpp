#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void append(Node *&Head, int data)
{

    Node *temp = new Node(data);

    Node *curr = Head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }
    curr->next = temp;
}
void show(Node *&Head)
{
    Node *curr = Head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int lengthOfList(Node *head)
{
    Node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
Node *deleteNode(Node *head, int delNodeNum)
{
    if (delNodeNum == 1)
    {
        Node *curr = head;
        head = head->next;
        curr->next = NULL;
        free(curr);
        return head;
    }
    else if (delNodeNum == 2)
    {

        Node *temp = head;
        temp = temp->next;
        Node *curr = temp;
        temp = temp->next;
        head->next = temp;
        curr->next = NULL;
        free(curr);
        return head;
    }

    Node *curr = head;
    Node *prv = NULL;
    int count = 1;

    while (count < delNodeNum)
    {
        prv = curr;
        curr = curr->next;
        count++;
    }

    prv->next = curr->next;
    curr->next = NULL;
    free(curr);
    return head;
}

Node *removeNthFromEnd(Node *head, int n)
{

    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL && n == 1)
    {
        return NULL;
    }

    int len = lengthOfList(head);
    int delNodeNum = len - n + 1;
    return deleteNode(head, delNodeNum);
}


int main(int argc, char const *argv[])
{
    Node *Head = new Node(10);

    append(Head, 20);
    append(Head, 30);
    append(Head, 40);
    append(Head, 50);
    show(Head);
    cout<<lengthOfList(Head)<<endl;
    cout<<lengthOfList(Head) - 1+1<<endl;
    Head = removeNthFromEnd(Head,1);
    show(Head);
    return 0;
}
