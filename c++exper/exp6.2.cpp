//实现链队列 front has data 王建辉
#include<stdio.h>
#include<malloc.h>
#include<iostream>
typedef char ElemType;
typedef struct DataNode
{
    ElemType data;
    struct DataNode *next;
}DataNode;

typedef struct
{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;

void InitQueue(LinkQuNode *&q)
{
    q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->rear = q->front = NULL;
}

void DestroyQueue(LinkQuNode *&q)
{
    DataNode *p = q->front,*r;
    if(p!=NULL)
    {
        r = p->next;
        while(r!=NULL)
        {
            free(p);
            p = r;r=p->next;
        }
    }
    free(p);//free node
    free(q);//free queue
}

bool QueueEmpty(LinkQuNode *q)
{
    return(q->rear == NULL);
}

void enQueue(LinkQuNode *&q,ElemType e)
{
    DataNode *p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if(q->rear == NULL)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

bool deQueue(LinkQuNode *&q,ElemType &e)
{
    DataNode *t;
    if(q->rear == NULL)
        return false;
    t = q->front;
    if(q->front == q->rear)//只有一个元素
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    e = t->data;
    free(t);
    return true;
}

