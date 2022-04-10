#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int *arr;
    int capacity;

public:
    Stack(int s)
    {
        top = -1;
        arr = new int[s];
        capacity = s;
    }

    void push(int element)
    {
        if(isFull()){
            cout<<"stack overflow"<<endl;
        }
        else{
            top++;
            arr[top] = element;
        }

    }

    void pop()
    {
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
        }
        else{
            top--;
        }

    }

    bool isFull()
    {
        return (top+1) == capacity;

    }

    bool isEmpty()
    {
        return (top==-1);

    }

    int getTop()
    {
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
        }
            return arr[top];
        
    }

    int getSize()
    {
        return top+1;

    }
};

int main()
{
    Stack st = Stack(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    cout<<st.getTop()<<endl;
    return 0;
}