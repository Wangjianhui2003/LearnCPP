//#include<stdio.h>
//#include<malloc.h>
#include<iostream>
using namespace std;
typedef char ElemType;

struct LinkNode
{
    ElemType data;
    LinkNode *next;
};
//头插法
void CreateListF(LinkNode *&L,ElemType array[],int n)
{
    LinkNode *s;
    L = new LinkNode;
    L -> next = nullptr;
    for(int i = 0;i<n;i++)
    {
        s = new LinkNode;
        s -> data = array[i];
        s -> next = L -> next;
        L -> next = s;
    }
}

//尾插法
void CreateListR(LinkNode *&L,ElemType array[],int n)
{
    LinkNode *s,*r;
    L = new LinkNode;
    L -> next = nullptr;
    r = L;
    for(int i = 0;i < n;i++)
    {
        s = new LinkNode;
        s->data = array[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}
//initlist
void InitList(LinkNode *&L)
{
    L = new LinkNode;
    L->next = nullptr;
}

//listinsert
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
    LinkNode *r = L,*s;
    int j = 1;
    if(i<=0)
        return false;
    while(j < i && r != NULL)
    {
        r = r->next;
        j++;
    }
    if(r == NULL)
        return false;
    else   
        {
            s = new LinkNode;
            s->data = e;
            s->next = r->next;
            r->next = s;
            return true;
        }
}

//listdelete

//destroylist
void DestroyList(LinkNode *&L)
{
    LinkNode *r = L->next,*p = L;
    
    while(r != nullptr)
    {
        delete p;
        p = p->next;
        r = p -> next;
    }
    delete p;
}

//listempty
int ListLength(LinkNode *L)
{
    LinkNode *n;
    int count = 0;
    n = L;
    while(n -> next != nullptr)
    {
        n = n->next;
        count++;
    }
    return count;
}

//displist
void DispList(LinkNode *L)
{
    LinkNode *node;
    while(node->next != nullptr)
    {
        cout<<node->data;
        node = node->next;
    }
    cout<<node<<endl;
}
//getelem

//locateElem
