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

    }

    void pop(){
        
    }
};

int main()
{
    return 0;
}