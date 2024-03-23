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

int getLength(ListNode *&head)
{
    ListNode *curr = head;
    int counter = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        counter++;
    }
    return counter;
}
ListNode *reverse(ListNode *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *curr = head;
    ListNode *prv = NULL;
    ListNode *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;

        curr->next = prv;

        prv = curr;
        curr = forward;
    }

    return prv;
}
ListNode *midListNode(ListNode *head, int len)
{
    ListNode *curr = head;
    ListNode *prv = NULL;

    int count = 0;

    while (count < (len)-1)
    {
        prv = curr;
        curr = curr->next;
        count++;
    }
    return curr;
}

void *reorderList(ListNode *&head)
{

    if (head->next == NULL)
    {
        int i = 1;
    }
    else if (head->next->next == NULL)
    {
        int i = 1;
    }
    else
    {

        int len = getLength(head) / 2;
        ListNode *mid = midListNode(head, len);
        ListNode *md = mid->next;
        mid->next = NULL;
        ListNode *curr2 = reverse(md);
        ListNode *curr1 = head;
        ListNode *frv1 = curr1;
        ListNode *frv2 = curr2;



        while (curr1 != NULL && curr2 != NULL)
        {
            frv1 = curr1->next;
            frv2 = curr2->next;

            curr1->next = curr2;
            curr2->next = frv1;

            curr1 = frv1;
            if (curr2->next == NULL)
            {
                break;
            }
            curr2 = frv2;
        }


        if (curr2 != NULL)
        {
            
            curr2->next = frv2;

        }

       
    }
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
    reorderList(head);
    show(head);

    return 0;
}