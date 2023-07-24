#include "exp6.2.cpp"//王建辉
#include<iostream>
using namespace std;
int main()
{
    ElemType e;
    LinkQuNode *q;
    InitQueue(q);
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    deQueue(q,e);
    cout<<e<<endl;
    enQueue(q,'d'); 
    enQueue(q,'e');
    enQueue(q,'f');
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        cout<<e<<endl;
    }
    DestroyQueue(q);
    
}//王建辉