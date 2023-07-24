#include<iostream>//王建辉
#include "exp6.0.cpp"
using namespace std;
int main()
{
    ElemType e;
    LinkStNode *s;
    InitStack(s);
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    while(!StackEmpty(s))
    {
        Pop(s,e);
        cout<<e<<" ";
    }
    cout<<endl;
    DestroyStack(s);
    return 1;

}