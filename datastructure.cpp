#include<iostream>
using namespace std;

#define MaxSize 100
typedef char ElemType;

struct SqStack
{
    ElemType data[MaxSize];
    int top;
};
//初始化栈
void InitStack(SqStack *&s)
{
    s = new SqStack;
    s -> top = -1;
}
//压入
bool Push(SqStack *&s,ElemType e)
{
    if(s -> top == MaxSize -1) return false;
    s -> top++;
    s -> data[s->top] = e;
    return true;
}
//弹出
bool Pop(SqStack *&s)
{
    if(s -> top == -1) return false;
    //e = s -> data[s -> top];
    s -> top--;
    return true;
}
//获取顶元素
bool Top(SqStack *s,ElemType &e)
{
    if(s -> top == -1 ) return false;
    e = s->data[s->top];
    return true;
}
//显示栈的所有元素
void Display(SqStack *s)
{
    int i = s->top;
    while(i != -1)
    {
        cout<<s->data[i]<<" ";
        i--;
    }
    cout<<endl;
}
//判空
bool Empty(SqStack *s)
{
    return(s->top == -1);
}
//释放
void Destroy(SqStack *&s)
{
    delete s;
}


int main()
{
    cout<<"创建一个空栈并初始化"<<endl;
    SqStack *s;
    InitStack(s);
    cout<<"压入h,i,j,k,l,m,n"<<endl;
    Push(s,'h');
    Push(s,'i');
    Push(s,'j');
    Push(s,'k');
    Push(s,'l');
    Push(s,'m');
    Push(s,'n');
    cout<<"输出栈内元素"<<endl;
    Display(s);
    cout<<"弹出栈顶元素并显示"<<endl;
    Pop(s);
    Display(s);
    cout<<"入栈s并显示"<<endl;
    Push(s,'s');
    Display(s);
    Destroy(s);
    return 0;

}