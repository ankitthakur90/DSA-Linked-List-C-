#include <iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void append(ListNode *&Head, int val)
{

    ListNode *temp = new ListNode(val);

    ListNode *curr = Head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }
    curr->next = temp;
}
void show(ListNode *&Head)
{
    ListNode *curr = Head;

    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

/*
)================                   ===============()
----------------  brute force        ---------------
)================                   ===============()
*/
stack<int> totalNodeSum(ListNode *head)
{
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    ListNode *curr = head;

    while (curr != NULL)
    {
        int digit = curr->val;
        s1.push(digit);
        s2.push(digit);
        curr = curr->next;
    }
    int carry = 0;

    while (!s1.empty())
    {
        int sum = s1.top() + s2.top() + carry;
        s1.pop();
        s2.pop();
        carry = sum / 10;
        sum = sum % 10;
        s3.push(sum);
    }
    if (carry)
    {
        s3.push(carry);
    }

    return s3;
}
ListNode *solve(ListNode *&head)
{
    stack<int> s = totalNodeSum(head);

    ListNode *curr = head;
    ListNode *prv = NULL;

    while (curr != NULL)
    {
        int digi = s.top();
        s.pop();
        curr->val = digi;
        prv = curr;
        curr = curr->next;
    }

    if (!s.empty())
    {

        while (!s.empty())
        {
            ListNode *temp = new ListNode;
            temp->val = s.top();
            s.pop();
            temp->next = NULL;
            prv->next = temp;
            prv = temp;
        }
    }
    return head;
}


////    changed the name of the funciton  because conflict  of same name fuctions
ListNode *doubleItBRT(ListNode *head)
{
    if (head->val == 0)
    {
        return head;
    }
    return solve(head);
}

/*
)================                   ===============()
----------------  Optimal solutio    ---------------
)================                   ===============()
*/

int NodeSum(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int carry = NodeSum(head->next);
    int sum = head->val * 2 + carry;
    carry = sum / 10;
    int rem = sum % 10;
    head->val = rem;
    return carry;
}
ListNode *doubleIt(ListNode *head)
{
    int carry = NodeSum(head);
    if (carry > 0)
    {
        ListNode *newListNode = new ListNode;
        newListNode->val = carry;
        newListNode->next = head;
        head = newListNode;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *Head = new ListNode(1);

    append(Head, 2);
    append(Head, 3);
    append(Head, 4);
    append(Head, 5);
    append(Head, 6);
    show(Head);
    doubleIt(Head);
    show(Head);

   cout<<endl;
   cout<<endl;

    Head = new ListNode(9);

    append(Head, 9);
    append(Head, 9);
    append(Head, 9);
    append(Head, 9);
    append(Head, 9);
    show(Head);
    doubleItBRT(Head);
    show(Head);
    return 0;
}
