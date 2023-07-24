#include "exp4.1.cpp"
#include<iostream>
using namespace std;
int main(){
    LinkNode *h;
    ElemType e;
    cout<<"循环单链表基本运算如下"<<endl;
    InitList(h);
    cout<<"尾插法插入abcde"<<endl;
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    cout<<"显示单链表"<<endl; 
    DispList(h);
    GetElem(h,3,e);
    cout<<"第三个元素"<<endl;
    ListInsert(h,4,'f');
    cout<<"插入f"<<endl;
    DispList(h);
    ListDelete(h,3,e);
    cout<<"删除第三元素"<<endl;
    DispList(h);
    DestroyList(h);
    return 0 ;

}//王建辉