//栈
#include<stdio.h>
#include<malloc.h>//王建辉
#define MaxSize 100
typedef char ElemType;
typedef double ElemType1;
typedef struct 
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *s){
    return(s->top == -1);
}

bool Push(SqStack *&s,ElemType e){
    if(s -> top == MaxSize-1) return false;
    s -> top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s,ElemType &e){
    if (s -> top == -1) return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s,ElemType &e)
{
    if(s->top == -1) return false;
    e = s->data[s->top];
    return true;
}



//----------------------------------------------


typedef struct 
{
    ElemType1 data[MaxSize];
    int top;
}SqStack1;

void InitStack1(SqStack1 *&s)
{
    s = (SqStack1 *)malloc(sizeof(SqStack1));
    s->top = -1;
}

void DestroyStack1(SqStack1 *&s)
{
    free(s);
}

bool StackEmpty1(SqStack1 *s){
    return(s->top == -1);
}

bool Push1(SqStack1 *&s,ElemType1 e){
    if(s -> top == MaxSize-1) return false;
    s -> top++;
    s->data[s->top] = e;
    return true;
}

bool Pop1(SqStack1 *&s,ElemType1 &e){
    if (s -> top == -1) return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop1(SqStack1 *s,ElemType1 &e)
{
    if(s->top == -1) return false;
    e = s->data[s->top];
    return true;
}