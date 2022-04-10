#include <bits/stdc++.h>
using namespace std;

class Stackdll
{
    struct node
    {
        int data;
        node *next;
        node *prev;
        node(int d)
        {
            data = d;
            next = 0;
            prev = 0;
        }
    };

    node *head;
    int size;

public:
    Stackdll()
    {
        head = 0;
        size = 0;
    }

    void push(int d){
        node* newnode = new node(d);
        if(head==0){
            head=newnode;
            size+=1;
        }
        else{
            head->next = newnode;
            newnode->prev = head;
            head = newnode;
            newnode->data = d;
            size+=1;
        }

    }

    void pop(){
        if(head==0){
            cout<<"stack underflow"<<endl;
        }
        else{
            node* toDelete = head;
            head = head->prev;
            delete toDelete;
            size-=1;
        }

    }

    void disply()
    {
        if(head==0)
        {
            cout<<"stack undeflow"<<endl;
        }
        else{
            node* cur = head;
            while(cur!=0)
            {
                cout<<cur->data<<"->";
                cur = cur->prev;
            }
            cout<<"end"<<endl;
        }
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Stackdll s = Stackdll();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.getSize()<<endl;
    return 0;
}