#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int s)
    {
        arr = new int[s];
        front = -1;
        rear = -1;
        size = s;
    }

    void enqueue(int key)
    {
        if(rear= size)
        {
            cout<<"queue is full"<<endl;
        }
        else if(rear==-1){
            front=0;
            rear=0;
            arr[rear] = key;
        }
        rear++;
    }

    void dequeue()
    {
        if(front == rear){
            cout<<"queue is empty"<<endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        return arr[front];
    }
};

int main()
{
    Queue q = Queue(6);
    q.enqueue(1);
    q.enqueue(2);
    cout<<q.getFront()<<endl;
    return 0;
}