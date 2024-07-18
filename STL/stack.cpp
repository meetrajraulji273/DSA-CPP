#include <bits/stdc++.h>
using namespace std;

void explainStack()
{
    cout << "Stack is a data structure that follows LIFO (Last In First Out) principle.It is a linear data structure that follows the principle of Last In First Out.It is a collection of elements that are inserted and removed from the same end.";

    cout << endl;
    cout << endl;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Size of stack is " << s.size() << endl;
    cout << "Top element of stack is " << s.top() << endl;
    s.pop();
    cout << "Size of stack is " << s.size() << endl;

    if (!s.empty())
    {
        cout << "the stack is not empty ";
    }
    else
    {
        cout << "the stack is empty ";
    }

    stack<int> s1;
    s.swap(s1);
}

int main()
{
    cout << "--------";
    cout << endl;
    cout << endl;

    explainStack();

    cout << endl;
    cout << endl;
    cout << "--------";
}