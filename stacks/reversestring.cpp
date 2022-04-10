#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s = "nithin";
    stack<char> s;

    for(int i=0; i<s.length(); i++)
    {
        s.push(s[i]);
    }

    string ans = "";
    while(!s.empty())
    {
        ans.push_back(s.top());

    }


    return 0;
}