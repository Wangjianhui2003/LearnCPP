#include "exp4.1.cpp"
#include<iostream>
using namespace std;
int main(){
    LinkNode *h;
    ElemType e;
    cout<<"ѭ�������������������"<<endl;
    InitList(h);
    cout<<"β�巨����abcde"<<endl;
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    cout<<"��ʾ������"<<endl; 
    DispList(h);
    GetElem(h,3,e);
    cout<<"������Ԫ��"<<endl;
    ListInsert(h,4,'f');
    cout<<"����f"<<endl;
    DispList(h);
    ListDelete(h,3,e);
    cout<<"ɾ������Ԫ��"<<endl;
    DispList(h);
    DestroyList(h);
    return 0 ;

}//������