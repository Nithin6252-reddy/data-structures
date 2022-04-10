#include <bits/stdc++.h>
using namespace std;

class Twostacks
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Twostacks(int s)
    {
        arr = new int[s];
        top1 = -1;
        top2 = size;
        size = s;
    }

    void push1(int element)
    {
        if(top2-top1 <= 0)
        {
            cout<<"stack overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = element;
        }

    }

    void push2(int element)
    {
        if(top2-top1 <= 0)
        {
            cout<<"stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = element;
        }

    }

    void pop1()
    {
        if(top1==-1)
        {
            cout<<"stack underflow"<<endl;
        }
        else{
            int ans = arr[top1];
            top1--;
            cout<<ans<<endl;
        }

    }

    void pop2()
    {
        if(top2==size)
        {

            cout<<"stack underflow"<<endl;
        }
        else{
            int ans = arr[top2];
            top2++;
            cout<<ans<<endl;
        }

    }


};

int main()
{
    return 0;
    Twostacks ts = Twostacks(6);
    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push2(1);
    ts.push2(2);
    ts.push2(3);
    ts.push2(4);
}