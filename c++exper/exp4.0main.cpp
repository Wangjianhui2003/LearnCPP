#include "exp4.0.cpp"
#include<iostream>
using namespace std;
int main(){
    DLinkNode *h;
    ElemType e;
    printf("˫���������������:\n");
    printf("��ʼ��˫����h\n");
    InitList(h);
    printf("���β���β�巨����Ԫ��a,b,c,d,e\n");
    ListInsert(h,1,'a');
    ListInsert(h,2,'b');
    ListInsert(h,3,'c');
    ListInsert(h,4,'d');
    ListInsert(h,5,'e');
    printf("���˫����\n");DispList(h);
    printf("˫����h����:%d\n",ListLength(h));
    printf("˫����hΪ%��\n",(ListEmpty(h)?"��":"�ǿ�"));
    GetElem(h,3,e);
    cout<<"����Ԫ��"<<e<<endl;
    cout<<"Ԫ��a��λ��"<<LocateElem(h,'a')<<endl;
    ListInsert(h,4,'f');
    ListDelete(h,3,e);
    DestroyList(h);
}//������
