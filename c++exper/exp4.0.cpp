//双链表
#include <stdio.h>
#include <malloc.h>
#ifndef EXP4
#define EXP4
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode * prior;
    struct DNode * next;
}DLinkNode;
//头插法建立双链表
void CreateListF(DLinkNode *&L,ElemType a[],int n)
{
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;

    for(int i = 0;i<n;i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;//插入节点next指向原节点
        if(L->next != NULL)L->next ->prior = s;//原第一个节点prior指向插入节点
        L->next = s;
        s->prior = L;
    }
}
//尾插法建立双链表
void CreateListR(DLinkNode *&L,ElemType a[],int n)
{
    DLinkNode *s,*r;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;

    r = L;
    for(int i = 0;i<n;i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        r->next = s;s->prior = r;
        r = s;
    }
    r->next = NULL;
}
//初始化线性表
void InitList(DLinkNode *&L)
{
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
}
//销毁线性表
void DestroyList(DLinkNode *&L)
{
    DLinkNode *pre = L,*p = pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre = p;
        p =pre->next;
    }
    free(pre);
}
//
bool ListEmpty(DLinkNode *L){
    return(L->next == NULL);
}
//
int ListLength(DLinkNode *L)
{
    DLinkNode *p = L;
    int i = 0;
    while(p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return(i);
}
//
void DispList(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while(p!= NULL)
    {
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}
//
bool GetElem(DLinkNode *L,int i,ElemType &e)
{
    int j = 0;
    DLinkNode *p = L;
    if(i<=0) return false;
    while(j<i && p!= NULL)
    {
        j++;
        p = p -> next;
    }
    if(p == NULL) return false;
    else{
        e = p ->data;
        return true;
    }
}
//
int LocateElem(DLinkNode *L,ElemType e)
{
    int i = 1;
    DLinkNode *p = L->next;
    while(p!=NULL && p->data!=e)
    {
        i++;
        p = p->next;
    }
    if(p==NULL) return 0;
    else return(i);
}
//
bool ListInsert(DLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    DLinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        if (p->next != NULL)
            p->next->prior = s;
        p->prior = p;
        p->next = s;
        return true;
    }
}
//
bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
    int j = 0;
    DLinkNode *p = L,*q;
    if(i <= 0) return false;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else
    {
        q = p->next;
        if(q==NULL) return false;
        e = q->data;
        p->next = q->next;
        if(p->next!=NULL) p->next->prior = p;
        free(q);
        return true;
    }
}//王建辉
#endif