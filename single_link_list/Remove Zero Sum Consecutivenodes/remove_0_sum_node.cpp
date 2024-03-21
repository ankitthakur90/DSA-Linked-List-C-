#include <iostream>
#include <vector>
#include<stack>
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

vector<int>solve(Node* Head){
    vector<int>res;
    stack<int> st;
    Node* curr = Head;
    while (curr != NULL )
    {
        res.push_back(curr->data);
        curr = curr->next;
    }
    curr = Head;
    st.push(curr->data);
    int i =0;
    while (!st.empty())
    {
        if(curr->data < 0 &&  (st.top() < 0)){
            st.push(curr->data);
        }
        else if((curr->data < 0  && st.top() > 0) ||(curr->data > 0  && st.top() < 0) ){
            int m = st.top();
            st.pop();
            int n = curr->data;
            int ns = m - n;
            st.push(ns);
        }
    }
    
    
}

int main(int argc, char const *argv[])
{
    Node *Node1 = new Node(1);

    Node *Head1 = Node1;

    append(Head1, 2);
    append(Head1, 3);
    append(Head1, 4);
    append(Head1, 5);
    append(Head1, 6);
    append(Head1, 7);
    append(Head1, 8);
    append(Head1, 9);

    // show(Head1);


    return 0;
}