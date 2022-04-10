#include <bits/stdc++.h>
using namespace std;

class Stackll
{

    struct node
    {
        int data;
        node *next;
        node(int d)
        {
            data = d;
            next = 0;
        }
    };

    node *head;
    int size;

public:
    Stackll()
    {
        head = 0;
        size = 0;
    }

    void push(int d)
    {
        node* newnode = new node(d);
        if(head==0)
        {
            head=newnode;
            size+=1;
        }
        else{
            newnode->next=head;
            newnode->data = d;
            head = newnode;
        }
    }

    void pop()
    {
        if(head==0)
        {
            cout<<"stack undeflow"<<endl;
            return;
        }
        else{
            node* toDel = head;
            head = head->next;
            delete toDel;
            size -= 1;
        }
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    return 0;
}