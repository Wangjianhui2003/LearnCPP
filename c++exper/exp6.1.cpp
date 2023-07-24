//实现环形队列_数组_王建辉
//rear指向新添加元素
#ifndef EXP6_1
#define EXP6_1
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MaxSize 100

typedef char ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

//free
void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//empty?
bool QueueEmpty(SqQueue *q)
{
    return(q->front == q->rear);
}

//push
bool enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MaxSize == q->front)
        return false; //判满
    q->rear = (q->rear+1)%MaxSize;
    q->data[q->rear] = e;
    return true;
}

//pop
bool deQueue(SqQueue *&q,ElemType &e)
{
    if(q->front == q->rear)
        return false;
    q->front = (q->front+1)%MaxSize;
    e = q->data[q->front];
    return true;
}
#endif