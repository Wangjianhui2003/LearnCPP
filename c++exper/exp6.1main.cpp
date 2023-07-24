#include<iostream>//王建辉
#include "exp6.1.cpp"
using namespace std;
int main()
{
    ElemType e;
    SqQueue *q;
    InitQueue(q);
    cout<<"input a,b,c,d,e"<<endl;
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    enQueue(q,'d');
    enQueue(q,'e');
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        cout<<e<<" ";
    }
    DestroyQueue(q);
    return 0;
}