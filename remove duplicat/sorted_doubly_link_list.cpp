// Problem Link -> https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void append(Node *&Head, Node *&Tail, int data)
{
    Node *temp = new Node(data);
    if (Head == NULL)
    {
        Head = temp;
        Head->prev = NULL;
        Head->next = NULL;
        Tail = temp;
        return;
    }

    Node *curr = Head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    temp->next = NULL;
    Tail = temp;
}

void display(Node *&Head)
{
    if (Head == NULL)
    {
        cout << " NO List Available" << endl;
        return;
    }
    Node *curr = Head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *removeDuplicat(Node *Head)
{

    if (Head == NULL)
    {
        return NULL;
    }
    if (Head->next == NULL)
    {
        return Head;
    }

    Node *curr = Head;

    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            return Head;
        }

        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            if (temp->next == NULL)
            {
                curr->next = NULL;
                temp->prev = NULL;
                free(temp);
            }
            else
            {
                curr->next = curr->next->next;
                temp->next->prev = curr;
                temp->next = NULL;
                temp->prev = NULL;
                free(temp);
            }

          
        }else{
            
        curr = curr->next;
        
        }
    }
    return Head;
}
int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(5);
    Node *Head = Node1;
    Node *Tail = Node1;

    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 10);
    append(Head, Tail, 20);
    append(Head, Tail, 20);
    append(Head, Tail, 20);
    append(Head, Tail, 30);
    append(Head, Tail, 30);
    append(Head, Tail, 30);
    append(Head, Tail, 30);
    append(Head, Tail, 30);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 40);
    append(Head, Tail, 50);
    append(Head, Tail, 60);

    display(Head);
 Head =   removeDuplicat(Head);
 display(Head);

    return 0;
}
