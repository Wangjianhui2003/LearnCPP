//实现链栈王建辉
#ifndef EXP6
#define EXP6
#include<iostream>
#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct linknode
{
    ElemType data;
    struct linknode *next;
}LinkStNode;

//initialization
void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

//free
void DestroyStack(LinkStNode *&s)
{
    LinkStNode *p = s->next;
    while(p!=NULL)
    {
        free(s);
        s = p;
        p = p->next;
    }
    free(s);
}

//empty?
bool StackEmpty(LinkStNode *s)
{
    return(s->next==NULL);
}

//push elem
void Push(LinkStNode *&s,ElemType e)
{
    LinkStNode *p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

//pop elem
bool Pop(LinkStNode *&s,ElemType &e)
{
    LinkStNode *p;
    if(s->next == NULL)
    {
        return false;
    }
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

//get top
bool GetTop(LinkStNode *s,ElemType &e)
{
    if(s->next == NULL)
    {
        return false;
    }
    e = s->next->data;
    return true;
}
#endif