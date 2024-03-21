#include <iostream>
#include <vector>
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
void append(ListNode *&Head, int data)
{

    ListNode *temp = new ListNode(data);

    ListNode *curr = Head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }
    curr->next = temp;

    temp->next = NULL;
}

void show(ListNode *&Head)
{
    ListNode *curr = Head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int getLength(ListNode *&Head)
{
    ListNode *curr = Head;
    int counter = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        counter++;
    }
    return counter;
}

ListNode *lastListNodelist2(ListNode *list2)
{
    ListNode *curr = list2;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    return curr;
}
ListNode *mergeInBetween(ListNode *&list1, int a, int b, ListNode *&list2)
{
    ListNode *lastListNodeOflist2 = lastListNodelist2(list2);

    ListNode *currlist1 = list1;
    ListNode *prev = currlist1;
    int count = 0;

    while (count < b)
    {

        if (count == (a - 1) && currlist1 != NULL)
        {
            prev = currlist1;
            currlist1 = currlist1->next;
            prev->next = list2;
            count++;
        }
        else
        {
            count++;
            currlist1 = currlist1->next;
        }
    }

    prev = currlist1;
    if (currlist1->next == NULL)
    {
        lastListNodeOflist2->next == NULL;
    }
    else
    {
        currlist1 = currlist1->next;
        prev->next = NULL;
        lastListNodeOflist2->next = currlist1;
    }

    return list1;
}

int main(int argc, char const *argv[])
{
    ListNode *ListNode1 = new ListNode(0);
    ListNode *ListNode2 = new ListNode(10001);

    ListNode *Head1 = ListNode1;
    ListNode *Head2 = ListNode2;

    append(Head1, 1);
    append(Head1, 2);
    append(Head1, 3);
    append(Head1, 4);
    append(Head1, 5);
    // append(Head1, 6);
    // append(Head1, 7);
    // append(Head1, 8);
    // append(Head1, 9);
    // append(Head1, 10);

    append(Head2, 10002);
    append(Head2, 10003);
    // append(Head2, 10004);

    show(Head1);
    show(Head2);

    ListNode *curr = mergeInBetween(Head1, 1,2 , Head2);
    show(curr);

    return 0;
}