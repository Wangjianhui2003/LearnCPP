#include "exp4.0.cpp"
#include<iostream>
using namespace std;
int main(){
    DLinkNode *h;
    ElemType e;
    printf("双链表基本运算如下:\n");
    printf("初始化双链表h\n");
    InitList(h);
    printf("依次采用尾插法插入元素a,b,c,d,e\n");
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    printf("输出双链表\n");DispList(h);
    printf("双链表h长度:%d\n",ListLength(h));
    printf("双链表h为%是\n",(ListEmpty(h)?"空":"非空"));
    GetElem(h,3,e);
    cout<<"第三元素"<<e<<endl;
    cout<<"元素a的位置"<<LocateElem(h,'a')<<endl;
    ListInsert(h,4,'f');
    ListDelete(h,3,e);
    DestroyList(h);
}//王建辉
