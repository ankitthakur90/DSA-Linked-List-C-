#include <iostream>
#include <vector>
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

    temp->next = NULL;
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

int getLength(Node *&Head)
{
    Node *curr = Head;
    int counter = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        counter++;
    }
    return counter;
}
void oneNull(Node *&head1, Node *&head2)
{

    Node *frw = NULL;
    Node *curr1 = NULL;
    Node *curr2 = NULL;
    if (head1 == NULL)
    {
        head1 = head2->next;
        curr1 = head1;
        curr2 = head2;
    }
    if (head2 == NULL)
    {
        head2 = head1->next;
        curr1 = head2;
        curr2 = head1;
    }

    bool flg = true;
    while (curr1 != NULL && curr2 != NULL)
    {
        frw = curr1->next;
        // cout<<"curr 1 : "<<curr1->data<<endl;
        // cout<<"curr 2 : "<<curr2->data<<endl;
        // cout<<"frw : "<<frw->data<<endl;
        if (frw == NULL)
        {
            curr1->next = NULL;
            curr2->next = NULL;
            cout << " first : ";
            show(head1);
            cout << " sedcond : ";
            show(head2);
            flg = false;
            break;
        }
        curr1->next = frw->next;
        curr2->next = frw;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    cout<<" out loop"<<endl;
    if (flg)
    {
        cout<<"in if 1:"<<endl;

        cout<<"in if 2:"<<endl;
        cout << " first : ";
        show(head1);
        cout << " sedcond : ";
        show(head2);
    }
}
void solve(Node *&head1, Node *&head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        oneNull(head1, head2);

        return;
    }
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *prv1 = NULL;
    Node *prv2 = NULL;
    Node *frw1 = NULL;
    Node *frw2 = NULL;
    Node *frw = NULL;
    vector<Node *> ans;

    while (curr1 != NULL && curr2 != NULL)
    {
        frw = curr1->next;
        prv1 = curr1;
        prv2 = curr2;
        curr1->next = curr2->next;
        curr2->next = frw;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if (curr1 == NULL && curr2 == NULL)
    {
        prv1->next = NULL;
        prv2->next = NULL;
        ans.push_back(head1);
        ans.push_back(head2);
        cout << "first ";
        show(head1);
        cout << "second : ";
        show(head2);
    }

    if (curr1 == NULL && curr2 != NULL)
    {
        curr1 = prv1;
        if (curr2->next == NULL)
        {
            curr1->next = NULL;
            curr2->next = NULL;
            show(head1);
            show(head2);
        }
        else
        {
            while (curr1 != NULL && curr2 != NULL)
            {
                frw = curr2->next;
                curr1->next = frw;
                curr1 = curr1->next;
                if (curr2->next == NULL)
                {
                    break;
                }
                curr2->next = frw->next;
                curr2 = curr2->next;
            }

            cout << "first ";
            show(head1);
            cout << "second : ";
            show(head2);
        }
    }

    if (curr1 != NULL && curr2 == NULL)
    {
        curr2 = prv2;
        if (curr1->next == NULL)
        {
            curr1->next = NULL;
            curr2->next = NULL;
            show(head1);
            show(head2);
        }
        else
        {
            while (curr1 != NULL && curr2 != NULL)
            {
                frw = curr1->next;
                curr2->next = frw;
                curr2 = curr2->next;
                if (curr1->next == NULL)
                {
                    break;
                }
                curr1->next = frw->next;
                curr1 = curr1->next;
            }

            cout << "first ";
            show(head1);
            cout << "second : ";
            show(head2);
        }
    }
}
vector<Node *> interweaveNodes(Node *&head1, Node *&head2)
{
    // Write your code here.t
}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(1);
    Node *Node2 = new Node(11);

    Node *Head1 = Node1;
    Node *Head2 = Node2;

    // append(Head1, 2);
    // append(Head1, 3);
    // append(Head1, 4);
    // append(Head1, 5);
    // append(Head1, 6);
    // append(Head1, 7);
    // append(Head1, 8);
    // append(Head1, 9);
    // append(Head1, 10);

    // append(Head2, 12);
    // append(Head2, 13);
    // append(Head2, 14);
    // append(Head2, 15);
    // append(Head2, 16);
    // append(Head2, 17);
    // append(Head2, 18);
    // append(Head2, 19);

    // show(Head1);
    show(Head2);

    solve(Head1, Head2);

    return 0;
}